/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:10:45 by buehara           #+#    #+#             */
/*   Updated: 2026/01/15 21:14:10 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_table	*table;
	t_philo	**philo;

	table = init_table(argc, argv);
	if (!table)
		return (1);
	philo = all_philos(table->philo);
	if (!philo)
	{
		free(table);
		printf("Malloc Error");
		return (1);
	}
	free_dinner(&philo, table->philo);
	free(table);
	return (0);
}
