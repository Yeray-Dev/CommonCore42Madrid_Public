/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:34:13 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:15:44 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*string;
	size_t	i1;
	size_t	i2;

	i1 = 0;
	i2 = 0;
	if (!s1 || !s2)
		return (NULL);
	string = malloc(ft_strlen(s1) + ft_strlen(s2) + 1 * sizeof(char));
	if (!string)
		return (NULL);
	while (i1 < ft_strlen(s1))
	{
		string[i1] = s1[i1];
		i1++;
	}
	while (i2 < ft_strlen(s2))
	{
		string[i1 + i2] = s2[i2];
		i2++;
	}
	string[i1 + i2] = '\0';
	return (string);
}
/*
int main()
{
	char string[50] = "Hola, ";
	char string2[50] = "Mundo";

	printf("%s\n", ft_strjoin(string, string2));
	return(0);
}
*/