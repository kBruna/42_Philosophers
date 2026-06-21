#include "philo.h"

long	ft_time(void)
{
	struct timeval milisec;

	if(gettimeofday(&milisec, NULL))
		return (0);
	return ((milisec.tv_sec * 1000) + (milisec.tv_usec / 1000));
}

int	is_alive(t_table *table)
{
	int	err;

	pthread_mutex_lock(&table->monitor);
	err = table->simulation;
	pthread_mutex_unlock(&table->monitor);
	return err;
}

void	philo_print(t_philo philo, int flag)
{
	long	time;

	pthread_mutex_lock(&philo.table->print);
	time = ft_time() - philo.table->start;
	if (flag == DIED)
		printf("%ld %ld died\n", time, philo.index);
	pthread_mutex_unlock(&philo.table->print);
	if (is_alive(philo.table) == 0)
		return ;
	pthread_mutex_lock(&philo.table->print);
	if (flag == FORK)
		printf("%ld %ld has taken a fork\n", time, philo.index);
	else if (flag == EAT)
		printf("%ld %ld is eating\n", time, philo.index);
	else if (flag == SLEEP)
		printf("%ld %ld is sleeping\n", time, philo.index);
	else if (flag == THINK)
		printf("%ld %ld is thinking\n", time, philo.index);
	pthread_mutex_unlock(&philo.table->print);
}

void	to_pass_time(t_philo *philo, long time)
{
	long	start;

	start = ft_time();
	while ((ft_time() - start) < time)
	{
		if(is_alive(philo->table) == 0)
			break;
		usleep(50);
	}
}

void	get_forks(t_philo *philo, pthread_mutex_t *first, pthread_mutex_t *sec)
{
	pthread_mutex_lock(first);
	philo_print(*philo, FORK);
	if (is_alive(philo->table) == 0)
	{
		pthread_mutex_unlock(first);
		return ;
	}
	pthread_mutex_lock(sec);
	pthread_mutex_lock(&philo->table->monitor);
	philo->last_meal = ft_time();
	pthread_mutex_unlock(&philo->table->monitor);
	philo_print(*philo, FORK);
	philo_print(*philo, EAT);
	to_pass_time(philo, philo->table->to_eat);
	pthread_mutex_unlock(sec);
	pthread_mutex_unlock(first);
	pthread_mutex_lock(&philo->table->monitor);
	philo->meals++;
	pthread_mutex_unlock(&philo->table->monitor);
}

void	ft_action(t_philo *philo, long time, t_action flag)
{
	if (is_alive(philo->table) == 0)
		return ;
	philo_print(*philo, flag);
	to_pass_time(philo, time);
	if (is_alive(philo->table) == 0)
		return ;
	philo_print(*philo, THINK);
}

void	to_eat(t_philo *philo)
{
	if (philo->index % 2 == 0 && philo->index + 1 == philo->table->philo)
		get_forks(philo, philo->right_fork, philo->left_fork);
	else if (philo->index % 2 == 0)
		get_forks(philo, philo->left_fork, philo->right_fork);
	else
		get_forks(philo, philo->right_fork, philo->left_fork);
}

void	*routine(void *philo)
{
	t_philo	*tmp;
	long	max_meals;
	long	meals;
	long	sleep;

	tmp = (t_philo *)philo;
	pthread_mutex_lock(&tmp->table->monitor);
	max_meals = tmp->table->max_meals;
	meals = tmp->meals;
	sleep = tmp->table->to_sleep;
	pthread_mutex_unlock(&tmp->table->monitor);
	while (is_alive(tmp->table))
	{
		if (max_meals && meals > max_meals)
			break ;
		if (is_alive(tmp->table)== 0)
			break ;
		to_eat(philo);
		if (is_alive(tmp->table) == 0)
			break ;
		ft_action(philo, sleep, SLEEP);
	}
	return (NULL);
}

void	kill_simulation(t_table *table)
{
	pthread_mutex_lock(&table->monitor);
	table->simulation = 0;
	pthread_mutex_unlock(&table->monitor);
}

int	wait_to_starve(t_table *table, long philo)
{
	long	time;
	long	last;
	long	to_die;
	long	idx;

	idx = 0;
	while (idx < philo)
	{
		time = ft_time();
		pthread_mutex_lock(&table->monitor);
		last = table->philos[idx].last_meal;
		to_die = table->to_die;
		pthread_mutex_unlock(&table->monitor);
		if (time - last > to_die)
		{
			/*
			pthread_mutex_lock(&table->monitor);
			table->simulation = 0;
			pthread_mutex_unlock(&table->monitor);
			*/
			kill_simulation(table);
			philo_print(table->philos[idx], DIED);
			return (1);
		}
		idx++;
	}
	return (0);
}

int	wait_to_eat(t_table *table, long philos, long max_meals)
{
	long	meals;
	long	has_eaten;
	long	idx;

	idx = 0;
	has_eaten = 0;
	meals = 0;
	while (max_meals && idx < philos)
	{
		pthread_mutex_lock(&table->monitor);
		meals = table->philos[idx].meals;
		pthread_mutex_unlock(&table->monitor);
		if (meals >= max_meals)
			has_eaten++;
		if (philos == has_eaten)
		{
			kill_simulation(table);
			return (1);
		}
		idx++;
	}
	return (0);
}

void	waiter(t_table *table)
{
	long	max_meals;
	long	philos;

	pthread_mutex_lock(&table->monitor);
	max_meals = table->max_meals;
	philos = table->philo;
	pthread_mutex_unlock(&table->monitor);
	while(1)
	{
		if (wait_to_starve(table, philos))
			break ;
		if (wait_to_eat(table, philos, max_meals))
			break ;
		/*
		if (max_meals)
		{
			pthread_mutex_lock(&table->monitor);
			meals = table->philos[idx].meals;
			pthread_mutex_unlock(&table->monitor);
			if (meals >= max_meals)
				has_eaten++;
			if (idx + 1 == philos && philos == has_eaten)
				return;
			if (idx + 1 == philos)
			{
				has_eaten = 0;
				idx = -1;
			}
		}
		*/
		usleep(500);
	}
}

void	ft_lone(t_philo *philo)
{
	philo_print(*philo, FORK);
	to_pass_time(philo, philo->table->to_die);
}

void	init_simulation(t_table *table)
{
	int	index;

	index = 0;
	table->start = ft_time();
	if (table->philo == 1)
		ft_lone(table->philos);
	while (table->philo != 1 && index < table->philo)
	{
		pthread_create(&table->philos[index].thread, NULL, routine, &table->philos[index]);
		index++;
	}
	index = 0;
	waiter(table);
	while (index < table->philo)
	{
		pthread_join(table->philos[index].thread, NULL);
		index++;
	}
}
