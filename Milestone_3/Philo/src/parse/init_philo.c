/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:33:28 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 20:27:09 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

void	init_philo(t_data *data)
{
	int	i;

	i = 0;
	data->philos = malloc(sizeof(t_philo) * data->n_philo);
	if (!data->philos)
	{
		write(2, "Philos cant allocate memory", 27);
		clean_memory(data);
		exit (FAILURE);
	}
	while (i < data->n_philo)
	{
		data->philos[i].id = i + 1;
		data->philos[i].count_eat = 0;
		data->philos[i].l_fork = i;
		data->philos[i].r_fork = (i + 1) % data->n_philo;
		data->philos[i].data = data;
		data->philos[i].last_meal = data->start_time;
		i++;
	}
}
