/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:50:08 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/18 12:27:00 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	simulation(t_data *data)
{
	int	i;
	int	err;

	i = 0;
	while (i < data->n_philo)
	{
		err = pthread_create(&data->philos[i].thread, NULL,
				philo_routine, &data->philos[i]);
		if (err != 0)
		{
			printf("Error with new thread\n");
			clean_memory(data);
			exit (FAILURE);
		}
		i++;
	}
	init_thread_death(data);
}
