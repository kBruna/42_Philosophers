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

// Parsing.c
int		arg_check(char *arg);
int		param_quantity(int argc);
int		parameters_verify(int argc, char **argv);
long	*parsing(int argc, char **argv);

// Philo_utils.c
int		return_error(char *msg, int flag);

// Philo_lib.c
int		ft_strlen(char *str);
long	ft_atol(char *str);
void	*ft_calloc(size_t nmemb, size_t size);

#endif
