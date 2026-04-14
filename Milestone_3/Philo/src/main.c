/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 09:16:53 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 20:26:29 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc < 5 || argc > 6)
	{
		write(1, "\n", 1);
		return (1);
	}
	init_data(&data, argc, argv);
	init_philo(&data);
	init_mutex_forks(&data);
	simulation(&data);
	clean_memory(&data);
	return (0);
}
