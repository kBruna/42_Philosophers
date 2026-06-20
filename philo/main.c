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
	t_table	*sim;

	sim = init_config(argc, argv);
	if (!sim)
		return (1);
	init_simulation(sim);
	free_dinner(sim);
	return (0);
}
