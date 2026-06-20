#include "philo.h"

long	ft_time(void)
{
	struct timeval milisec;

	if(gettimeofday(&milisec, NULL))
		return (0);
	return ((milisec.tv_sec * 1000) + (milisec.tv_usec / 1000));
}

void	philo_print(t_philo philo, int flag)
{
	long	time;

	pthread_mutex_lock(&philo.table->print);
	time = ft_time() - philo.table->start;
	if (flag == FORK)
		printf("[ %04ld ] Philo %ld has taken a fork\n", time, philo.index);
	else if (flag == EAT)
		printf("[ %04ld ] Philo %ld is eating\n", time, philo.index);
	else if (flag == SLEEP)
		printf("[ %04ld ] Philo %ld is sleeping\n", time, philo.index);
	else if (flag == THINK)
		printf("[ %04ld ] Philo %ld is thinking\n", time, philo.index);
	else if (flag == DIED)
		printf("[ %04ld ] Philo %ld died\n", time, philo.index);
	pthread_mutex_unlock(&philo.table->print);
}

void	to_sleep(t_philo *philo, long time)
{
	long	start;

	start = ft_time();
	while ((ft_time() - start) < time)
	{
		usleep(50);
		if ((ft_time() - philo->last_meal) > (*philo).table->to_die)
		{
			break ;
		}
	}
}

void	*routine(void *philo)
{
	t_philo	*tmp;

	tmp = (t_philo *)philo;
	if (tmp->is_alive)
	{
		philo_print(*tmp, SLEEP);
		to_sleep(tmp, tmp->table->to_sleep);
	}
	return (NULL);
}

void	init_simulation(t_table *table)
{
	int	index;

	index = 0;
	table->start = ft_time();
	while (index < table->philo)
	{
		pthread_create(&table->philos[index].thread, NULL, routine, &table->philos[index]);
		index++;
	}
	index = 0;
	while (index < table->philo)
	{
		pthread_join(table->philos[index].thread, NULL);
		index++;
	}
}
