#include <stdio.h>
#include <string.h>
#include "libftprintf.h"

int	main(void)
{
	ft_printf("ft_printf: Hello!\n");
	printf("printf      :%i\n", 100);
	printf("printf      :%i\n", 100);
	printf("printf 0    :%0i\n", 100);
	printf("printf +    :%+i\n", 100);
	printf("printf space:% i\n", 100);
	printf("printf -    :%-i\n", 100);
	printf("printf      :%10i\n", 100);
	printf("printf 0    :%010i\n", 100);
	printf("printf +    :%+10i\n", 100);
	printf("printf space:% 10i\n", 100);
	printf("printf -    :%-10i\n", 100);
	return (0);
}
