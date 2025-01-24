/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:47:23 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:14:07 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	int		i;
	char	*number;

	i = 0;
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
	}
	number = ft_itoa(n);
	if (!number)
		return ;
	while (number[i])
	{
		write (fd, &number[i], 1);
		i++;
	}
	free(number);
}

/*
int main()
{
	ft_putnbr_fd(-7483648,  1);
	return 0;
}
*/
