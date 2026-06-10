/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:10:55 by buehara           #+#    #+#             */
/*   Updated: 2026/01/15 21:10:57 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	arg_check(char *arg)
{
	int	idx;

	if (!arg)
		return (0);
	idx = 0;
	while (arg[idx] != '\0')
	{
		if (arg[idx] > '9' || arg[idx] < '0' || arg[idx] != ' ')
			return (0);
	}
	return (1);
}

int	param_quantity(int argc)
{
	if (argc < 5 || argc > 6)
	{
		return_error("Wrong Number of Parameters", ERROR_PARAMETERS);
		return (0);
	}
	return (1);
}

int	parameters_verify(int argc, char **argv)
{
	int	idx;

	idx = 1;
	while (idx < argc)
	{
		if (argv[idx][0] == '\0')
		{
			return_error("Null Parameters", NULL);
			return (0);
		}
		if (!arg_check(argv[idx]))
		{
			return_error("Invalid Parameters", NULL);
			return (0);
		}
		idx++;
	}
	return (1);
}

int	*parsing(int argc, char **argv)
{
	int	idx;
	int	*nbr;

	idx = 0;
	if (!param_quantity(argc))
		return (NULL);
	if (!parameters_verify(argc, argv))
		return (NULL);
	nbr = malloc(sizeof(int) * (argc - 1));
	if (!nbr)
		return (NULL);
	while (--idx > 0)
		nbr[idx - 1] = ft_atoi(argv[idx]);
	return (nbr);
}
