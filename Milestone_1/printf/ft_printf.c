/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
<<<<<<< HEAD
/*   By: yblanco- <yblanco-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:49:50 by yblanco-          #+#    #+#             */
/*   Updated: 2025/01/19 12:38:47 by yblanco-         ###   ########.fr       */
=======
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 13:49:50 by yblanco-          #+#    #+#             */
/*   Updated: 2025/02/08 15:45:19 by yblanco-         ###   ########.fr       */
>>>>>>> 77ac9b5dc78f984c53c393953b93388882fab905
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
<<<<<<< HEAD
=======
#include <limits.h>
>>>>>>> 77ac9b5dc78f984c53c393953b93388882fab905

static void	ft_print_type(char type, va_list *args, int *cs)
{
	if (type == 'd' || type == 'i')
		ft_print_basic(type, args, cs);
	else if (type == 's')
		ft_print_basic(type, args, cs);
	else if (type == 'c')
		ft_print_basic(type, args, cs);
	else if (type == 'p')
		ft_print_basic(type, args, cs);
	else if (type == 'u')
		ft_print_special(type, args, cs);
	else if (type == 'x')
		ft_print_special(type, args, cs);
	else if (type == 'X')
		ft_print_special(type, args, cs);
	else if (type == '%')
		ft_print_special(type, args, cs);
}

int	ft_printf(char const *format, ...)
{
	int	i;
	int	*cs;

	va_list (args);
	va_start (args, format);
<<<<<<< HEAD

=======
>>>>>>> 77ac9b5dc78f984c53c393953b93388882fab905
	i = 0;
	cs = malloc(sizeof(int) * 1);
	*cs = 0;
	while (format[i])
	{
		if (format[i] == '%' && format[i++])
			ft_print_type(format[i], &args, cs);
		else
		{
			write(1, &format[i], 1);
			(*cs)++;
		}
<<<<<<< HEAD
		i++;
=======
		if (format[i])
			i++;
>>>>>>> 77ac9b5dc78f984c53c393953b93388882fab905
	}
	va_end(args);
	i = cs[0];
	free(cs);
	return (i);
}
<<<<<<< HEAD

// int	main(void)
// {

// 	printf("%d y %c\n", 9, 'a');
// 	ft_printf("%d y %c\n", 9, 'a');
// 	return (0);
// }

// int	main()
// {
// 	int n_ft = 0;
// 	int n = 0;

// 	n_ft = ft_printf("%u", -1); printf(" |FT: %d\n",n_ft);
// 	n = printf("%u", -1); printf(" | : %d\n",n);
// 	return(0);
// }

// #include "ft_printf.h"
// #include <stdio.h>
// #include <limits.h>
// int main(void)
// {
// int n_ft;
// int n;
// char str[5] = "hola";
// //! CARÁCTERES
// printf("---------------------------\n");
// printf("TEXTO SIN FORMATO\n");
// n_ft = ft_printf("esto es una prueba"); printf(" |FT: %d\n",n_ft);
// n = printf("esto es una prueba"); printf(" | : %d\n",n);
// printf("---------------------------\n");
// printf("CARÁCTERES\n");
// n_ft = ft_printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%c %c %c %c", 'H','O','L','A'); printf(" | Carácteres: %d\n",n);

// n_ft = ft_printf("%c", 126); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%c", 126); printf(" | Carácteres: %d\n",n);

// n_ft = ft_printf("%c %c %c", '0',0,'1'); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%c %c %c", '0',0,'1'); printf(" | Carácteres: %d\n",n);

// //! STRINGS
// printf("---------------------------\n");
// printf("STRINGS\n");
// char *ptr = str;
// n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);

// ptr = NULL;
// n_ft = ft_printf("%s",ptr); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%s",ptr); printf(" | Carácteres: %d\n",n);
// //! PUNTEROS
// printf("---------------------------\n");
// printf("PUNTEROS\n");
// char *my_ptr = NULL;
//     n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);
// my_ptr = str;
// n_ft = ft_printf("%p",my_ptr); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%p",my_ptr); printf(" | Carácteres: %d\n",n);

// //! DECIMALES CON SIGNO
// printf("---------------------------\n");
// printf("DECIMALES CON SIGNO\n");
// n_ft = ft_printf("%d",2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%d",2147483647); printf(" | Carácteres: %d\n",n);

// //! DECIMALES SIN SIGNO
// printf("---------------------------\n");
// printf("DECIMALES SIN SIGNO\n");
// n_ft = ft_printf("%u",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%u",-2147483647); printf(" | Carácteres: %d\n",n);
// //! ENTEROS
// printf("---------------------------\n");
// printf("ENTEROS\n");
// n_ft = ft_printf("%i",-2147483647); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("%i",-2147483647); printf(" | Carácteres: %d\n",n);
// //! HEXADECIMALES
// printf("---------------------------\n");
// printf("HEXADECIMALES\n");
// unsigned int hex = 0;
// n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
// hex = 9841678;
// n_ft = ft_printf("x: %x | X: %X",hex,hex); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf("x: %x | X: %X",hex,hex); printf(" | Carácteres: %d\n",n);
// //! PORCENTAJES
// printf("---------------------------\n");
// printf("PORCENTAJES\n");
//   n_ft = ft_printf("1%%1"); printf(" | Carácteres FT: %d\n",n_ft);
// n = printf(" %% ");  printf(" | Carácteres: %d\n",n);
// system("leaks -q a.out");
// return (0);
// }
=======
>>>>>>> 77ac9b5dc78f984c53c393953b93388882fab905
