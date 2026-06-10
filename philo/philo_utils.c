/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:11:11 by buehara           #+#    #+#             */
/*   Updated: 2026/01/15 21:16:20 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(char *str)
{
	int	nbr;
	int	idx;

	nbr = 0;
	idx = 0;
	if (!str)
		return (0);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		nbr = nbr * 10 + (str[idx] - '0');
		idx++;
	}
	return (nbr);
}

int	ft_strlen(char *str)
{
	int	idx;

	idx = 0;
	while (str && str[idx] != '\0')
		idx++;
	return (idx);
}
