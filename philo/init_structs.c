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

t_table	*init_config(int argc, char **argv)
{
	t_table	*table;

	table = init_table(argc, argv);
	if (!table)
		return (NULL);
	table->philos = all_philos(table);
	if (table->philos && init_fork_left(table))
	{
		free_dinner(table);
		return (NULL);
	}
	init_fork_right(table);
	return (table);
}

void	fill_table(t_table *table, long *nbr)
{
	table->simulation = 0;
	table->philo = nbr[0];
	table->to_die = nbr[1];
	table->to_eat = nbr[2];
	table->to_sleep = nbr[3];
	table->max_meals = -1;
	table->philos = NULL;
	if (nbr[4])
		table->max_meals = nbr[4];
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
	fill_table(table, nbr);
	free(nbr);
	if(pthread_mutex_init(&table->print, NULL))
	{
		free_dinner(table);
		return (NULL);
	}
	return (table);
}

t_philo	*all_philos(t_table *table)
{
	t_philo	*array;
	long	index;

	array = ft_calloc(sizeof(t_philo), table->philo + 1);
	if (!array)
		return (NULL);
	index = 0;
	while (index < table->philo)
	{
		array[index].index = index;
		array[index].is_alive = 1;
		array[index].last_meal = 0;
		array[index].meals = 0;
		array[index].table = table;
		array[index].thread = 0;
		index++;
	}
	return (array);
}
