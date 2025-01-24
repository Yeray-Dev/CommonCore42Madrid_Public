/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:26:21 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:14:42 by yblanco-         ###   ########.fr       */
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
/*
int main() 
{
	
	const char *str = "Hola, Mundo!";
	char ch = 'w';

	
	char *result = ft_strchr(str, ch);

	if (result == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, result);


	char *r1esult = strchr(str, ch);

	if (r1esult == NULL)
	{
		printf("No hay coindicidencias");
	}else
		printf("El carácter '%c' se encontró en la cadena: %s\n", ch, r1esult);

}
*/