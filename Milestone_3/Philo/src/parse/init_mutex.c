/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:17:08 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/18 12:27:25 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	clean_mutex(pthread_mutex_t *forks, int mutex_init)
{
	int	i;

	i = 0;
	while (i < mutex_init)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

static int	check_mutex(int err)
{
	if (err != 0)
	{
		write(2, "ERROR: Init mutex wrong\n", 24);
		return (FAILURE);
	}
	return (SUCCESS);
}

void	init_mutex_forks(t_data *data)
{
	int	i;
	int	err;
	int	check;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->n_philo);
	if (!data->forks)
	{
		write(2, "Forks cant allocate memory", 27);
		clean_memory(data);
		exit (FAILURE);
	}
	while (i < data->n_philo)
	{
		err = pthread_mutex_init(&data->forks[i], NULL);
		check = check_mutex(err);
		if (check == FAILURE)
		{
			clean_mutex(data->forks, i);
			clean_memory(data);
			exit (FAILURE);
		}
		i++;
	}
	init_mutex (data);
}

void	init_mutex(t_data *data)
{
	int	err;
	int	check;

	err = pthread_mutex_init(&data->print_mutex, NULL);
	check = check_mutex(err);
	if (check == FAILURE)
		exit (FAILURE);
	err = pthread_mutex_init(&data->dead_mutex, NULL);
	check = check_mutex(err);
	if (check == FAILURE)
		exit (FAILURE);
	err = pthread_mutex_init(&data->meal_mutex, NULL);
	check = check_mutex(err);
	if (check == FAILURE)
		exit (FAILURE);
	err = pthread_mutex_init(&data->eat_mutex, NULL);
	check = check_mutex(err);
	if (check == FAILURE)
		exit (FAILURE);
}
