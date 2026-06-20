/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:11:20 by buehara           #+#    #+#             */
/*   Updated: 2026/06/19 15:53:20 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

// Structs

typedef enum e_action
{
	FORK,
	EAT,
	SLEEP,
	THINK,
	DIED
}			t_action;


typedef struct s_philo	t_philo;

typedef struct s_table
{
	long			philo;
	long			to_eat;
	long			to_sleep;
	long			to_die;
	long			max_meals;
	long			start;
	t_philo			*philos;
	pthread_mutex_t	print;
	int				simulation;
}				t_table;

struct	s_philo
{
	long			index;
	long			last_meal;
	long			meals;
	long			is_alive;
	t_table			*table;
	pthread_t		thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
};

// Parsing.c
int		arg_check(char *arg);
int		param_quantity(int argc);
int		parameters_verify(int argc, char **argv);
long	*parsing(int argc, char **argv);

// Init_structs.c
t_philo	*all_philos(t_table *table);
t_table	*init_table(int argc, char **argv);
t_table	*init_config(int argc, char **argv);

// Forks.c
int		init_fork_left(t_table *table);
void	init_fork_right(t_table *table);

// Philo_utils.c
int		return_error(char *msg, int flag);

// Philo_lib.c
int		ft_strlen(char *str);
long	ft_atol(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

//init_sim.c
void	init_simulation(t_table *table);

//Free
void	free_dinner(t_table *table);

#endif
