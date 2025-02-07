/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_redirect.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:22:01 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 15:52:32 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(unsigned long int new_n, int *cs)
{
	size_t		count;

	count = 0;
	if (new_n == 0)
	{
		write(1, "0", 1);
		(*cs)++;
		return (0);
	}
	while ((new_n != 0) && (count++ >= 0))
		new_n = new_n / 10;
	(*cs) += count;
	return (count);
}

static void	ft_itoa_unsigned(unsigned int n, int	*cs)
{
	char				*number;
	size_t				count;
	unsigned long int	new_n;

	new_n = (unsigned long int)n;
	count = ft_count(new_n, cs);
	if (new_n == 0)
		return ;
	number = (char *)ft_calloc(count + 1, sizeof(char));
	if (number == NULL)
		return ;
	while (count-- != 0)
	{
		number[count] = new_n % 10 + '0';
		new_n /= 10;
	}
	count = 0;
	while (number[count])
		write (1, &number[count++], 1);
	free(number);
}

void	ft_print_basic(char type, va_list *args, int *cs)
{
	int					number;
	char				c;
	char				*str;
	unsigned long long	pointer;

	if (type == 'd' || type == 'i')
	{
		number = va_arg(*args, int);
		ft_putnbr_fd(number, 1, cs);
	}
	else if (type == 's')
	{
		str = va_arg(*args, char *);
		ft_putstr_fd(str, 1, cs);
	}
	else if (type == 'c')
	{
		c = (char)va_arg(*args, int);
		ft_putchar_fd(c, 1, cs);
	}
	else if (type == 'p')
	{
		pointer = (unsigned long long)va_arg(*args, void *);
		ft_hexa_pointer(pointer, cs);
	}
}

void	ft_print_special(char type, va_list *args, int *cs)
{
	unsigned int	unsigned_number;

	if (type == 'u')
	{
		unsigned_number = va_arg(*args, unsigned long int);
		ft_itoa_unsigned(unsigned_number, cs);
	}
	else if (type == 'x')
	{
		unsigned_number = va_arg(*args, unsigned long long int);
		ft_hexa(unsigned_number, type, cs);
	}
	else if (type == 'X')
	{
		unsigned_number = va_arg(*args, unsigned long long int);
		ft_hexa(unsigned_number, type, cs);
	}
	else if (type == '%')
	{
		write(1, "%", 1);
		(*cs)++;
	}
}
