/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:43:36 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 16:55:18 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	c1;
	char			*string;
	size_t			len;

	c1 = (unsigned char) c;
	len = ft_strlen(s);
	string = (char *) s;
	if (c1 == '\0')
		return (&string[len]);
	while (len > 0)
	{
		if (string[len - 1] == c1)
			return (&string[len - 1]);
		len--;
	}
	return (NULL);
}
/*
int main() 
{
	
	const char *str = "Hola, hola!";
	char ch = 'a';

	
	char *result = ft_strrchr(str, ch);

	if (result == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, result);


	char *r1esult = ft_strrchr(str, ch);

	if (r1esult == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, r1esult);

}
*/