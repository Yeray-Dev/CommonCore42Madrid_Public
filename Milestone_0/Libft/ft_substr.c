/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:01:09 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/22 12:12:18 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;

	i = ft_strlen(s);
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (i - start < len)
		len = i - start;
	str = (char *) malloc(len + 1 * sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (i < len && s[start + i])
	{
		str[i] = s[start + i];
		i++;
	}
	str[len] = '\0';
	return (str);
}
/*
int main()
{
	char s[50] = "";
	char *str = ft_substr(s, 2, 50);
	printf("%s\n", str);
	free(str);
}
*/