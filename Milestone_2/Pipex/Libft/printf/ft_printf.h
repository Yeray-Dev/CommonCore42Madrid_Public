/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/14 09:35:19 by yblanco-          #+#    #+#             */
/*   Updated: 2025/07/04 11:22:55 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
# include <unistd.h>
# include "../libft.h"

void	ft_print_basic(char type, va_list *args, int *cs);
void	ft_print_special(char type, va_list *args, int *cs);
int		ft_printf(char const *format, ...);
void	*ft_hexa(unsigned int number, char type, int	*cs);
void	*ft_hexa_pointer(unsigned long long pointer, int	*cs);

#endif