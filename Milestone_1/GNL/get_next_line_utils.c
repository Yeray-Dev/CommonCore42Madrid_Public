/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:15:15 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 19:32:12 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *org_str, char *bff)
{
	size_t	i;
	size_t	n;
	char	*str;

	if (!org_str)
	{
		org_str = (char *)malloc(1 * sizeof(char));
		org_str[0] = '\0';
	}
	if (!org_str || !bff)
		return (NULL);
	str = malloc(sizeof(char) * ((ft_strlen(org_str) + ft_strlen(bff)) + 1));
	if (str == NULL)
		return (NULL);
	i = -1;
	n = 0;
	if (org_str)
		while (org_str[++i] != '\0')
			str[i] = org_str[i];
	while (bff[n] != '\0')
		str[i++] = bff[n++];
	str[ft_strlen(org_str) + ft_strlen(bff)] = '\0';
	free(org_str);
	return (str);
}

char	*ft_line(char *str, int *rest)
{
	int		i;
	char	*new_str;

	i = 0;
	if (!str[i])
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new_str = (char *)malloc(sizeof(char) * (i + 2));
	if (!new_str)
		return (NULL);
	*rest = i;
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	if (str[i] == '\n')
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i] = '\0';
	return (new_str);
}

char	*ft_next_str(char *str, int *rest)
{
	int		i;
	int		n;
	char	*new_str;

	i = (*rest);
	if (!str[i])
	{
		free(str);
		return (NULL);
	}
	new_str = (char *) malloc(sizeof(char) * (ft_strlen(str) - i + 1));
	if (!new_str)
		return (NULL);
	i++;
	n = 0;
	while (str[i])
		new_str[n++] = str[i++];
	new_str[n] = '\0';
	free(str);
	return (new_str);
}
