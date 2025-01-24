/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 17:04:31 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/24 09:25:35 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include <stdio.h>
// #include "libft.h"

int	ft_toupper(int c)
{
	if (c <= 122 && c >= 97)
	{
		c = c - 32;
	}
	return (c);
}