/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_fdf.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:53:03 by yblanco-          #+#    #+#             */
/*   Updated: 2025/08/01 17:25:11 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"
#include "../Include/fdf.h"

int	letter_count_fdf(const char *s, char c, int position)
{
	int	len;

	len = 0;
	while (s[position + len] != c && s[position + len])
		len++;
	return (len);
}

int	extract_word_fdf(char const *s, char c, int *position, char **string1)
{
	int	len;

	while (s[*position] == c)
		(*position)++;
	len = letter_count_fdf(s, c, *position);
	*string1 = ft_substr(s, *position, len);
	if (!(*string1))
		return (0);
	*position += len;
	return (1);
}

char	**ft_split_fdf(char const *s, char c, int words)
{
	int				i;
	int				position;
	char			**string1;

	string1 = malloc(sizeof(char *) * (words + 1));
	if (!string1)
		return (NULL);
	i = 0;
	position = 0;
	while (i < words)
	{
		if (!extract_word_fdf(s, c, &position, &string1[i]))
		{
			while (i > 0)
				free(string1[--i]);
			free(string1);
			return (NULL);
		}
		i++;
	}
	string1[i] = NULL;
	return (string1);
}
