/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:37:57 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:15:56 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
#include <stddef.h>
//#include <unistd.h>
#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t n)
{
	size_t	src_len;
	size_t	dest_len;
	size_t	i;

	src_len = ft_strlen(src);
	dest_len = ft_strlen(dest);
	i = 0;
	if (dest_len >= n)
		return (n + src_len);
	while (src[i] != '\0' && (dest_len + i) < (n -1))
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	if (dest_len + i < n)
		dest[dest_len + i] = '\0';
	return (dest_len + src_len);
}
/*
int main ()
{
	 char str[50] = "Holla1, Mundo!!";
	 char dest[50] = "estos";
	 printf("%zu", ft_strlcpy(dest, str, 50));
}
*/