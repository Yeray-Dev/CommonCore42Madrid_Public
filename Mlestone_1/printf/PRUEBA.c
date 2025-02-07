#include <stdio.h>
#include <unistd.h>

// int main()
// {
// 	char *str;
// 	printf("%p\n", str);
// }

int main()
{
	char			*pointer = "1234536354";
	unsigned long	number;
	char			hexa[20];
	int				digit;
	size_t			len;

	number = (unsigned long) pointer;
	printf("%lu", number);
	// len = 0;

	// hexa[len++] = '0';
	// hexa[len++] = 'x';
	// len = ft_hexa_count(number);
	// if (number == 0)
	// 	hexa[len++] = '0';
	// while (number != 0)
	// {
	// 	digit = number % 16;
	// 	if (digit < 10)
	// 		hexa[len++] = '0' + digit;
	// 	else
	// 		hexa[len++] = 'a' + (digit - 10);
	// 	number /= 16;
	// }

	// ft_hexa_write(hexa);
	return (0);
}