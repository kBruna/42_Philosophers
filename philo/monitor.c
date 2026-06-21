/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:05:21 by buehara           #+#    #+#             */
/*   Updated: 2026/06/20 22:05:23 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	wait_to_starve(t_table *table, long philo)
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
			kill_simulation(table);
			philo_print(table->philos[idx], DIED);
			return (1);
		}
		idx++;
	}
	return (0);
}

static int	wait_to_eat(t_table *table, long philos, long max_meals)
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
	while (1)
	{
		if (wait_to_starve(table, philos))
			break ;
		if (wait_to_eat(table, philos, max_meals))
			break ;
		usleep(500);
	}
}
