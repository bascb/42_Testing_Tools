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
		chars = ft_printf("Int: %.10i %+5.10i % 5.10i", 23, 55, 75);
		ft_printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = ft_printf("Uns: %.10u %30.10u %-20.10u", 23, 130, 55);
		ft_printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = ft_printf("Hex: %.10x %-10.X", 23, 420);
		ft_printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = ft_printf("Hex: %.10x %55.10x", -23, 0);
		ft_printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = ft_printf("Int: %-100.10i", -23);
		ft_printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = ft_printf("Int: %.10i %+.10i", 0, 0);
		ft_printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = ft_printf("Int: %.10s %20.10s", "ab", "cd");
		ft_printf(" %i", chars);
	}
	if (test == 8)
	{
		chars = ft_printf("Int: % 35.10i %+55.10i", 0, 0);
		ft_printf(" %i", chars);
	}
	return (0);
}
