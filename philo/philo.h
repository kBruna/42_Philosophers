/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: buehara <buehara@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 21:11:20 by buehara           #+#    #+#             */
/*   Updated: 2026/01/15 21:17:33 by buehara          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

# define ERROR_PARAMETERS "Recommended Use: >$ ./philosophers\
        <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep>\
		[number_of_times_each_philosopher_must_eat]"

// Parsing.c
int	arg_check(char *arg);
int	param_quantity(int argc);
int	parameters_verify(int argc, char **argv);
int	*parsing(int argc, char **argv);

// Philo_utils.c
int	ft_atoi(char *str);
int	ft_strlen(char *str);

// Main.c
int	return_error(char *msg, char *msg2);
#endif
