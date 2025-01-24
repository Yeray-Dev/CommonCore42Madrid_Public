/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:43:36 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:14:01 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
//  #include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char *) s;
	while (i < n)
	{
		string[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
/*
int main ()
{
    char str[50] = "Hola, Mundo!";
    ft_memset(str, 96, 3);
    printf("%s", str);
    return(0);
}
*/
