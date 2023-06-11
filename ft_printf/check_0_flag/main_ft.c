#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	test;
	int	chars;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
	{
		chars = ft_printf("Int: %010i", 23);
		ft_printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = ft_printf("Uns: %010u", 23);
		ft_printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = ft_printf("Hex: %010x", 23);
		ft_printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = ft_printf("Hex: %010x", -23);
		ft_printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = ft_printf("Int: %010i", -23);
		ft_printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = ft_printf("Int: %+010i", 23);
		ft_printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = ft_printf("Int: %010i %+010i", 0, 0);
		ft_printf(" %i", chars);
	}
	return (0);
}
