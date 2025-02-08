/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:35:19 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 15:45:48 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include <limits.h>

void	ft_print_basic(char type, va_list *args, int *cs);
void	ft_print_special(char type, va_list *args, int *cs);
int		ft_printf(char const *format, ...);
void	ft_putnbr_fd(int n, int fd, int *cs);
void	ft_putstr_fd(char *s, int fd, int *cs);
void	ft_putchar_fd(char c, int fd, int *cs);
char	*ft_itoa(int n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_hexa(unsigned long long int number, char type, int	*cs);
void	*ft_hexa_pointer(unsigned long long pointer, int	*cs);

#endif