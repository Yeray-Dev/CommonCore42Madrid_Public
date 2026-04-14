/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_typedef.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:29 by yblanco-          #+#    #+#             */
/*   Updated: 2026/03/02 11:08:05 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHER_TYPEDEF_H
# define PHILOSOPHER_TYPEDEF_H

typedef enum e_exit_status
{
	SUCCESS,
	FAILURE
}	t_exit_status;

typedef enum e_bool
{
	FALSE,
	TRUE
}	t_bool;

typedef struct s_data
{
	int				n_philo;
	int				its_all;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_to_eat;
	long long		start_time;
	volatile t_bool	is_dead;
	pthread_t		death_thread;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	dead_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	eat_mutex;
	struct s_philo	*philos;
}	t_data;

typedef struct s_philo
{
	int			id;
	int			l_fork;
	int			r_fork;
	int			count_eat;
	long long	last_meal;		
	int			thread_ready;
	pthread_t	thread;
	t_data		*data;
}	t_philo;

#endif