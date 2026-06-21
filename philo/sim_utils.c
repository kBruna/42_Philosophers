/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sim_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/20 22:05:27 by buehara           #+#    #+#             */
/*   Updated: 2026/06/20 22:05:29 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	kill_simulation(t_table *table)
{
	pthread_mutex_lock(&table->monitor);
	table->simulation = 0;
	pthread_mutex_unlock(&table->monitor);
}

void	ft_lone(t_philo *philo)
{
	philo_print(*philo, FORK);
	to_pass_time(philo, philo->table->to_die);
}

void	to_pass_time(t_philo *philo, long time)
{
	long	start;

	start = ft_time();
	while ((ft_time() - start) < time)
	{
		if (is_alive(philo->table) == 0)
			break ;
		usleep(50);
	}
}

int	is_alive(t_table *table)
{
	int	err;

	pthread_mutex_lock(&table->monitor);
	err = table->simulation;
	pthread_mutex_unlock(&table->monitor);
	return (err);
}

void	philo_print(t_philo philo, int flag)
{
	long	time;

	pthread_mutex_lock(&philo.table->print);
	time = ft_time() - philo.table->start;
	if (flag == DIED)
		printf("%ld %ld died\n", time, philo.index);
	pthread_mutex_unlock(&philo.table->print);
	if (is_alive(philo.table) == 0)
		return ;
	pthread_mutex_lock(&philo.table->print);
	if (flag == FORK)
		printf("%ld %ld has taken a fork\n", time, philo.index);
	else if (flag == EAT)
		printf("%ld %ld is eating\n", time, philo.index);
	else if (flag == SLEEP)
		printf("%ld %ld is sleeping\n", time, philo.index);
	else if (flag == THINK)
		printf("%ld %ld is thinking\n", time, philo.index);
	pthread_mutex_unlock(&philo.table->print);
}
