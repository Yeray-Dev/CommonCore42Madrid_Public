/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 16:39:21 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:25:18 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	index_b;
	size_t	index_l;

	index_b = 0;
	if (little[0] == 0)
		return ((char *)big);
	while (big[index_b] && index_b < len)
	{
		index_l = 0;
		if (little[index_l] == big[index_b])
		{
			while ((big[index_b + index_l] == little[index_l]
					&& big[index_b + index_l] && index_b + index_l < len))
				index_l++;
			if (little[index_l] == 0)
			{
				return ((char *)&big[index_b]);
			}
		}
		index_b++;
	}
	return (NULL);
}