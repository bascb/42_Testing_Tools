#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;
	int	chars;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
	{
		chars = ft_printf("Int: %10i %1i", 23, 100);
		ft_printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = ft_printf("Uns: %10u %10u", 23, -10);
		ft_printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = ft_printf("Hex: %10x %10X %1x", 120, 120, 120);
		ft_printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = ft_printf("Char: %10c %1c", 'a', 'b');
		ft_printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = ft_printf("String: %10s %1s", "ases", "grandes!!");
		ft_printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = ft_printf("Int: %+10i %+1i", 23, 100);
		ft_printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = ft_printf("Int: %+10i %1i", 0, 0);
		ft_printf(" %i", chars);
	}
	if (test == 8)
	{
		chars = ft_printf("%197c %-1c", 7, 120);
		ft_printf(" %i", chars);
	}
	if (test == 9)
	{
		chars = ft_printf("%12p", (void*)18229185041105221837lu);
		ft_printf(" %i", chars);
	}
	if (test == 10)
	{
		chars = ft_printf("8 %013i\n", -1488496170);
		ft_printf(" %i", chars);
	}
	return (0);
}
