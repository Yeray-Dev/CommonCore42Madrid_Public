/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:53:03 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:14:27 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "libft.h"

int	words_count(const char *s, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i -1] == c))
			count++;
		i++;
	}
	return (count);
}

int	letter_count(const char *s, char c, int position)
{
	int	len;

	len = 0;
	while (s[position + len] != c && s[position + len])
		len++;
	return (len);
}

int	extract_word(char const *s, char c, int *position, char **string1)
{
	int	len;

	while (s[*position] == c)
		(*position)++;
	len = letter_count(s, c, *position);
	*string1 = ft_substr(s, *position, len);
	if (!(*string1))
		return (0);
	*position += len;
	return (1);
}

char	**ft_split(char const *s, char c)
{
	int				count;
	int				i;
	int				position;
	char			**string1;

	count = words_count(s, c);
	string1 = malloc(sizeof(char *) * (count + 1));
	if (!string1)
		return (NULL);
	i = 0;
	position = 0;
	while (i < count)
	{
		if (!extract_word(s, c, &position, &string1[i]))
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
/*
int main() 
{
    char s[200] = "Hola me llamo laura";
    char **string1 = ft_split(s, 'l'); // Usamos espacio como delimitador.

    // Imprimir los string1ados
    for (int i = 0; string1[i] != NULL; i++) {
        printf("Palabra %d: %s\n", i, string1[i]);
        free(string1[i]); // Liberamos cada subcadena.
    }
    free(string1); // Liberamos el puntero al arreglo de punteros.

    return 0; 
}
*/
