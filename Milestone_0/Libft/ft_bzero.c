/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 12:16:49 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 12:25:42 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*string;

	i = 0;
	string = (char *) s;
	while (i < n)
	{
		string[i] = '\0';
		i++;
	}
}
/*
int main ()
{
  char str[20] = "Hola, Mundo!";

    // Imprimir el string original
    printf("Antes de ft_bzero: %s\n", str);

    // Aplicar la función ft_bzero sobre una porción del array
    ft_bzero(str + 5, 3);  

   
    printf("Bytes después de ft_bzero:\n%s", str);
    for (int i = 0; i < 20; i++) {
        printf("%02x ", (unsigned char)str[i]);
    }
    printf("\n");
}
*/
