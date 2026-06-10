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

int	return_error(char *msg, char *msg2)
{
	write(STDERR_FILENO, &"Error: ", 7);
	write(STDERR_FILENO, msg, ft_strlen(msg));
	write(STDERR_FILENO, &"\n", 1);
	if (msg2)
	{
		write(STDERR_FILENO, msg2, ft_strlen(msg2));
		write(STDERR_FILENO, &"\n", 1);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	*nbr;

	nbr = parsing(argc, argv);
	if (!nbr)
		return (1);
	for (int i = 0; i < argc - 1; i++)
		printf("%d\n", nbr[i]);
	return (0);
}
