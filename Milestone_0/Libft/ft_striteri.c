/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yblanco- <yblanco-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/04 14:30:22 by yblanco-          #+#    #+#             */
/*   Updated: 2024/10/04 17:15:36 by yblanco-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i])
	{
		f (i, &s[i]);
		i++;
	}
}
/*
int main() {
	 // Test 1: Cadena normal
	char str1[] = "hola, mundo!";
	ft_striteri(str1, to_upper);
	printf("Test 1 - Cadena normal: %s\n", str1); // Esperado: "HOLA, MUNDO!"

	// Test 2: Cadena vacía
	char str2[] = "";
	ft_striteri(str2, to_upper);
	printf("Test 2 - Cadena vacía: %s\n", str2); // Esperado: ""

	// Test 3: Cadena NULL
	char *str3 = NULL;
	ft_striteri(str3, to_upper); // No debería fallar
	printf("Test 3 - Cadena NULL: OK (sin fallo)\n");

	// Test 4: Función NULL
	char str4[] = "prueba";
	ft_striteri(str4, NULL); // No debería fallar
	printf("Test 4 - Función NULL: %s\n", str4);

	// // Test 5: Función que no modifica nada
	// char str5[] = "No cambio";
	// ft_striteri(str5, do_nothing); // No debería modificar la cadena
	// printf("Test 5 - Sin cambios: %s\n", str5); 

	// Test 6: Cadena con caracteres especiales
	char str6[] = "123 !@# Hola!";
	ft_striteri(str6, to_upper);
	printf("Test 6 - Caracteres especiales: %s\n", str6); 

	// Test 7: Cadena con mayúsculas
	char str7[] = "Ya ESTABA en MAYÚSCULAS";
	ft_striteri(str7, to_upper);
	printf("Test 7 - Mayúsculas: %s\n", str7); 

	return 0;
}
*/