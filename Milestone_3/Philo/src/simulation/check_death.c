/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:40:15 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 20:34:28 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosopher.h"

static void handle_death(t_data *data, int i)
{
	pthread_mutex_unlock(&data->meal_mutex);
	print_mutex(&data->philos[i], "is dead");
	data->is_dead = TRUE;
	clean_memory(data);
	exit(SUCCESS);
}

void	check_must_eat(t_data *data)
{
	if (data->must_to_eat >= 1)
	{
		pthread_mutex_lock(&data->eat_mutex);
		if (data->its_all == data->n_philo)
		{
			data->is_dead = TRUE;
		}
		pthread_mutex_unlock(&data->eat_mutex);
	}
}

void	*check_death(void *arg)
{
	t_data		*data;
	int			i;
	long long	now;

	data = (t_data *) arg;
	// Ensure function terminates with return NULL
	while (!data->is_dead)
	{
		usleep(100);
		now = get_time_in_ms();
		i = 0;
		while (i < data->n_philo)
		{
			pthread_mutex_lock(&data->meal_mutex);
			if ((now - data->philos[i].last_meal) > data->time_to_die)
				handle_death(data, i);
			pthread_mutex_unlock(&data->meal_mutex);
			check_must_eat(data);
			i++;
		}
	}
	return NULL;
}

void	init_thread_death(t_data *data)
{
	int	err;

	err = pthread_create(&data->death_thread, NULL, check_death, data);
	if (err != 0)
	{
		printf("Error al crear el hilo\n");
		clean_memory(data);
		exit (FAILURE);
	}
	err = pthread_join(data->death_thread, NULL);
	if (err != 0)
	{
		printf("Error en la funcion Join el hilo\n");
		clean_memory(data);
		exit (FAILURE);
	}
}