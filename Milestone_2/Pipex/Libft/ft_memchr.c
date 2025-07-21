/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:59:05 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:24:04 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;
	unsigned char	copy;

	i = 0;
	string = (unsigned char *) s;
	copy = (unsigned char) c;
	while (i < n)
	{
		if (string[i] == copy)
			return ((void *)(string + i));
		i++;
	}
	return (NULL);
}