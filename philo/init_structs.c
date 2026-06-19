/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:52:16 by buehara           #+#    #+#             */
/*   Updated: 2026/06/19 15:52:29 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_fork_right(t_table *table)
{
	long	i;
	long	qtt;

	i = 0;
	qtt = table->philo;
	while (i < qtt)
	{
		table->philos[i].right_fork = table->philos[(i + 1) % qtt].left_fork;
		i++;
	}
}

int	init_fork_left(t_table *table)
{
	long	index;
	long	qtt;

	index = 0;
	qtt = table->philo;
	while (index < qtt)
	{
		table->philos[index].left_fork = malloc(sizeof(pthread_mutex_t));
		if (!table->philos[index].left_fork)
		{
			free_dinner(table);
			return (1);
		}
		if (pthread_mutex_init(table->philos[index].left_fork, NULL))
			pthread_mutex_destroy(table->philos[index].left_fork);
		index++;
	}
	return (0);
}

t_table	*init_config(int argc, char **argv)
{
	t_table	*table;

	table = init_table(argc, argv);
	if (!table)
		return (NULL);
	table->philos = all_philos(table->philo, table);
	if (table->philos && init_fork_left(table))
	{
		free_dinner(table);
		return (NULL);
	}
	init_fork_right(table);
	return (table);
}

t_table	*init_table(int argc, char **argv)
{
	long	*nbr;
	t_table	*table;

	nbr = parsing(argc, argv);
	if (!nbr)
		return (NULL);
	table = ft_calloc(sizeof(t_table), 1);
	if (!table)
	{
		free(nbr);
		return (NULL);
	}
	table->simulation = 0;
	table->philo = nbr[0];
	table->to_die = nbr[1];
	table->to_eat = nbr[2];
	table->to_sleep = nbr[3];
	table->max_meals = -1;
	table->philos = NULL;
	if (nbr[4])
		table->max_meals = nbr[4];
	free(nbr);
	return (table);
}

t_philo	*all_philos(long qtt_philo, t_table *table)
{
	t_philo	*array;
	long	index;

	array = ft_calloc(sizeof(t_philo), qtt_philo);
	if (!array)
		return (NULL);
	index = 0;
	while (index < qtt_philo)
	{
		array[index].index = index;
		array[index].is_alive = 1;
		array[index].last_meal = 0;
		array[index].meals = 0;
		array[index].table = table;
		index++;
	}
	return (array);
}
