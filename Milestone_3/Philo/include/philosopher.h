/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:52:26 by yblanco-          #+#    #+#             */
/*   Updated: 2026/03/02 20:23:55 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_H
# define PHILOSOPHER_H

//. Librarys

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include "philosopher_typedef.h"

//. Funtions

//? Parse 
// init_data.c
void		init_data(t_data *data, int argc, char **argv);
void 		clean_memory(t_data *data);
// init_mutex.c
void		init_mutex(t_data *data);
void		init_mutex_forks(t_data *data);
// init_philo.c
void		init_philo(t_data *data);
// ft_atoi.c
int			ft_atoi(const char *str);
//? Simulation
// simulation.c
void		simulation(t_data *data);
// philo_routine
void		*philo_routine(void *arg);
// utils.c
long long	get_time_in_ms(void);
// t_bool		check_end_conditions(t_data *data);
void		print_mutex(t_philo *philo, char *action);
void		handle_one_philo(t_data *data);
//check_death.c
void		init_thread_death(t_data *data);
void		*check_death(void *arg);

#endif