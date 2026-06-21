/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sim.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 21:50:43 by buehara           #+#    #+#             */
/*   Updated: 2026/06/20 21:54:08 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
		if (is_alive(tmp->table) == 0)
			break ;
		to_eat(philo);
		if (is_alive(tmp->table) == 0)
			break ;
		ft_action(philo, sleep, SLEEP);
	}
	return (NULL);
}

void	init_simulation(t_table *table)
{
	int	idx;

	idx = 0;
	table->start = ft_time();
	if (table->philo == 1)
		ft_lone(table->philos);
	while (table->philo != 1 && idx < table->philo)
	{
		pthread_create(&table->philos[idx].thread, NULL,
			routine, &table->philos[idx]);
		idx++;
	}
	idx = 0;
	waiter(table);
	while (idx < table->philo)
	{
		pthread_join(table->philos[idx].thread, NULL);
		idx++;
	}
}
