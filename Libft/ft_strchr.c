/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:26:21 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:24:46 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strchr(const char *s, int c)
{
	unsigned char	c1;
	int				i;
	char			*string;

	c1 = (unsigned char) c;
	i = 0;
	string = (char *) s;
	while (string[i] != '\0')
	{
		if (string[i] == c1)
			return (&string[i]);
		i++;
	}
	if (c1 == '\0')
		return (&string[i]);
	return (NULL);
}