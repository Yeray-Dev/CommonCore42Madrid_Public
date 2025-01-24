/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 13:18:43 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:11:46 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
// #include <stdio.h>

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*string1;
	unsigned char	*string2;
	size_t			i;

	string1 = (unsigned char *) s1;
	string2 = (unsigned char *) s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (string1[i] != string2[i])
			return (string1[i] - string2[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char s1[20] = "b";
	char s2[20] = "a";
	printf("%d\n", ft_memcmp(s1, s2, 10));
	printf("%d", memcmp(s1, s2, 10));
}
*/
