/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:40:21 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:24:18 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	const char	*s;
	char		*d;

	s = src;
	d = dst;
	i = 0;
	if (s > d)
	{
		while (len > 0)
		{
			d[i] = s[i];
			i++;
			len--;
		}
	}
	if (s < d)
	{
		while (len > 0)
		{
			d[len - 1] = s[len - 1];
			len--;
		}
	}
	return (dst);
}