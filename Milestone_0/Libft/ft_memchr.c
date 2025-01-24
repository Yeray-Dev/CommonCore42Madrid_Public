/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:59:05 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:11:39 by yblanco-         ###   ########.fr       */
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

/*
int main() 
{
	
	const char *str = "Hola, Mundo!";
	char ch = 'u';

	
	char *result = ft_strrchr(str, ch);

	if (result == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, result);


	char *r1esult = ft_memchr(str, ch, 7);

	if (r1esult == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, r1esult);

}*/