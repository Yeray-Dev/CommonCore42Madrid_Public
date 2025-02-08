/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 09:36:51 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 16:12:41 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexa_count(unsigned long long number, int	*cs)
{
	int	len;

	len = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		(*cs) += 1;
	}
	while (number != 0)
	{
		number /= 16;
		len++;
	}
	(*cs) += len;
	return (len);
}

static void	ft_hexa_write(char	*hexa)
{
	int		i;

	i = 0;
	while (hexa && hexa[i])
	{
		write(1, &hexa[i], 1);
		i++;
	}
	free(hexa);
	hexa = NULL;
}

void	*ft_hexa(unsigned long long number, char type, int	*cs)
{
	int		len;
	int		aux;
	char	*hexa;

	len = ft_hexa_count(number, cs);
	aux = 0;
	hexa = malloc((len + 1) * sizeof(char));
	if (!hexa)
		return (0);
	hexa[len] = '\0';
	while (number && len > 0)
	{
		aux = number % 16;
		if (aux < 10)
			hexa[len - 1] = aux + '0';
		else if (aux >= 10 && type == 'x')
			hexa[len - 1] = (aux - 10) + 'a';
		else
			hexa[len - 1] = (aux - 10) + 'A';
		number /= 16;
		len--;
	}
	ft_hexa_write(hexa);
	return (0);
}

void	*ft_hexa_ptr(unsigned long long number, char type, int	*cs)
{
	int		len;
	int		aux;
	char	*hexa;

	len = ft_hexa_count(number, cs);
	aux = 0;
	hexa = malloc((len + 1) * sizeof(char));
	hexa[len] = '\0';
	if (number == 0)
		hexa[0] = '0';
	while (len > 0)
	{
		aux = number % 16;
		if (aux < 10)
			hexa[len - 1] = aux + '0';
		else if (aux >= 10 && type == 'x')
			hexa[len - 1] = (aux - 10) + 'a';
		else
			hexa[len - 1] = (aux - 10) + 'A';
		number /= 16;
		len--;
	}
	ft_hexa_write(hexa);
	return (0);
}

void	*ft_hexa_pointer(unsigned long long pointer, int *cs)
{
	if (pointer == 0)
	{
		write(1, "(nil)", 5);
		(*cs) += 5;
		return (0);
	}
	write(1, "0", 1);
	write(1, "x", 1);
	(*cs) += 2;
	ft_hexa_ptr(pointer, 'x', cs);
	return (0);
}
