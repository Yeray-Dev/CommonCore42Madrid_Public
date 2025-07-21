/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:47:23 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 15:50:16 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	is_min(int n, int fd, int *cs)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		(*cs) += 11;
		return (0);
	}
	return (1);
}

void	ft_putnbr_fd(int n, int fd, int *cs)
{
	int		i;
	int		count;
	char	*number;

	i = 0;
	count = 0;
	if (!is_min(n, fd, cs))
		return ;
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		count = 1;
	}
	number = ft_itoa(n);
	if (!number)
		return ;
	while (number[i])
		write (fd, &number[i++], 1);
	free(number);
	(*cs) += (i + count);
}
