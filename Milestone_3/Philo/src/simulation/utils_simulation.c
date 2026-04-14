/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:53:16 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 10:56:38 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

long long	get_time_in_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000LL + tv.tv_usec / 1000);
}

void	print_mutex(t_philo *philo, char *action)
{
	int	timestamp;

	pthread_mutex_lock(&philo->data->print_mutex);
	timestamp = get_time_in_ms() - philo->data->start_time;
	printf("%d %d %s\n", timestamp, philo->id, action);
	pthread_mutex_unlock(&philo->data->print_mutex);
}

void	handle_one_philo(t_data *data)
{
	long long	start;

	start = get_time_in_ms();
	printf("%lld 1 has taken a fork\n", get_time_in_ms() - start);
	usleep(data->time_to_die * 1000);
	printf("%lld 1 died\n", get_time_in_ms() - start);
	exit(SUCCESS);
}
