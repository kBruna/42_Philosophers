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

long	ft_atol(char *str)
{
	long	nbr;
	int		idx;

	nbr = 0;
	idx = 0;
	if (!str)
		return (0);
	while (str[idx] >= '0' && str[idx] <= '9')
	{
		if (nbr >= 214748364 && str[idx] > 7)
			return (-1);
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

void	*ft_calloc(size_t nmemb, size_t size)
{
	int		byte_size;
	int		index;
	char	*mem;

	if (!nmemb || !size)
	{
		mem = malloc(1);
		if (!mem)
			return (NULL);
		return (mem);
	}
	if (2147483647 / size < nmemb)
		return (NULL);
	byte_size = nmemb * size;
	mem = malloc(nmemb * size);
	if (!mem)
		return (NULL);
	index = 0;
	while (index < byte_size)
		mem[index++] = 0;
	return ((void *)mem);
}
