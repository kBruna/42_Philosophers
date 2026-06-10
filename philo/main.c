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
	long	*nbr;

	nbr = parsing(argc, argv);
	if (!nbr)
		return (1);
	for (int i = 0; i < argc - 1; i++)
		printf("%ld\n", nbr[i]);
	free(nbr);
	return (0);
}
