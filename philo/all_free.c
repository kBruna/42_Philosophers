/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_free.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/19 15:51:15 by buehara           #+#    #+#             */
/*   Updated: 2026/06/19 15:51:46 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_dinner(t_table *table)
{
	long	index;

	index = 0;
	while (index < table->philo)
	{
		pthread_mutex_destroy(table->philos[index].left_fork);
		free(table->philos[index].left_fork);
		table->philos[index].left_fork = NULL;
		index++;
	}
	free(table->philos);
	free(table);
}
