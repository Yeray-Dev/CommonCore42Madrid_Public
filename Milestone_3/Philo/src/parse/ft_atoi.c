/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yerayblancodelafuente <yerayblancodelaf    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/02 10:24:42 by yerayblanco       #+#    #+#             */
/*   Updated: 2026/03/02 10:39:43 by yerayblanco      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philosopher.h"

int	ft_atoi(const char *str)
{
	int	convert;
	int	i;
	int	negative;

	i = 0;
	convert = 0;
	negative = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			convert = (convert * 10) + (str[i] - '0');
			i++;
		}
		else
			return (0);
	}
	return (convert * negative);
}
