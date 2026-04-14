/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_routine.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:47:11 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/18 12:27:05 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	think(t_philo *philo)
{
	print_mutex(philo, "is thinking");
	if (philo->id % 2 != 0)
		usleep(1000);
}

static void	eat(t_philo *philo)
{
	if (philo->data->n_philo == 1)
		handle_one_philo(philo->data);
	pthread_mutex_lock(&philo->data->forks[philo->l_fork]);
	print_mutex(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->forks[philo->r_fork]);
	print_mutex(philo, "has taken a fork");
	pthread_mutex_lock(&philo->data->meal_mutex);
	philo->last_meal = get_time_in_ms();
	pthread_mutex_unlock(&philo->data->meal_mutex);
	print_mutex(philo, "is eating");
	usleep(philo->data->time_to_eat * 1000);
	pthread_mutex_lock(&philo->data->eat_mutex);
	philo->count_eat++;
	if (philo->data->must_to_eat >= 1)
	{
		if (philo->data->must_to_eat == philo->count_eat)
			philo->data->its_all++;
	}
	pthread_mutex_unlock(&philo->data->eat_mutex);
	pthread_mutex_unlock(&philo->data->forks[philo->l_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->r_fork]);
}

static void	sleep_philo(t_philo *philo)
{
	long long	start;

	print_mutex(philo, "is sleeping");
	start = get_time_in_ms();
	while (!philo->data->is_dead && get_time_in_ms() - start
		< philo->data->time_to_sleep)
		usleep(100);
}

void	*philo_routine(void *arg)
{
	t_philo	*philos;

	philos = (t_philo *)arg;
	while (!philos->data->is_dead)
	{
		if (philos->data->must_to_eat > 0
			&& philos->count_eat >= philos->data->must_to_eat)
			break ;
		think(philos);
		eat(philos);
		sleep_philo(philos);
	}
	return (NULL);
}
