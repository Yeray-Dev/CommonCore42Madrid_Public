/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:36:33 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:24:13 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
#include <stddef.h>
// #include <unistd.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*str_dest;
	unsigned char	*str_src;
	int				i;
	int				size;

	if (!dest && !src)
		return (NULL);
	i = 0;
	size = (int) n;
	str_dest = (unsigned char *) dest;
	str_src = (unsigned char *) src;
	while (i < size)
	{
		str_dest[i] = str_src[i];
		i++;
	}
	return (str_dest);
}