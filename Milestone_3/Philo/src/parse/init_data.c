/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:34:01 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 20:25:23 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

static void	check_arg(t_data *data)
{
	if (data->n_philo <= 0)
	{
		write(2, "Philo's number is wrong\n", 25);
		exit (FAILURE);
	}
	if (data->time_to_die <= 0)
	{
		write(2, "Time to die is wrong\n", 21);
		exit (FAILURE);
	}
	if (data->time_to_eat <= 0)
	{
		write(2, "Time to eat is wrong\n", 21);
		exit (FAILURE);
	}
	if (data->time_to_sleep <= 0)
	{
		write(2, "Time to sleep is wrong\n", 23);
		exit (FAILURE);
	}
}

void	init_data(t_data *data, int argc, char **argv)
{
	data->n_philo = ft_atoi(argv[1]);
	data->time_to_die = ft_atoi(argv[2]);
	data->time_to_eat = ft_atoi(argv[3]);
	data->time_to_sleep = ft_atoi(argv[4]);
	data->must_to_eat = -1;
	data->its_all = 0;
	if (argc == 6)
	{
		data->must_to_eat = ft_atoi(argv[5]);
		if (data->must_to_eat <= 0)
		{
			write(2, "Must to eat is wrong\n", 21);
			exit (FAILURE);
			clean_memory(data);
		}
	}
	data->philos = NULL;
	data->is_dead = FALSE;
	data->start_time = get_time_in_ms();
	check_arg(data);
}

void clean_memory(t_data *data)
{
    free(data->philos);
    free(data->forks);
}