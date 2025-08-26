/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:41:25 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:25:08 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
// #include <stdio.h>
// #include <bsd/string.h>
#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t n)
{
	size_t			i;
	size_t			len_src;

	i = 0;
	len_src = ft_strlen(src);
	while (i < (n - 1) && src[i] != '\0' && n != 0)
	{
		dest[i] = src[i];
		i++;
	}
	if (n != 0)
		dest[i] = '\0';
	return (len_src);
}