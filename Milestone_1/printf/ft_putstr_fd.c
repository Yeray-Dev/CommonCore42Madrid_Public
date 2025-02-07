/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:51:54 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 15:51:01 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr_fd(char *s, int fd, int	*cs)
{
	int	i;

	if (!s)
	{
		write (1, "(null)", 6);
		(*cs) += 6;
		return ;
	}
	i = 0;
	while (s[i])
	{
		write (fd, &s[i], 1);
		i++;
		(*cs)++;
	}
}
