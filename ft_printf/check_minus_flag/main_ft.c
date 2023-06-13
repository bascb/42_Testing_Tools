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
		chars = ft_printf("Int: %-10i %-10i", 23, -23);
		ft_printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = ft_printf("Uns: %-10u", 23);
		ft_printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = ft_printf("Hex: %-10x %-10X", 120, 120);
		ft_printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = ft_printf("Char: %-10c", 'a');
		ft_printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = ft_printf("String: %-10s", "ases");
		ft_printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = ft_printf(" %-1c %-2c %-3c ", '0', 0, '1');
		ft_printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = ft_printf(" %-11p %-12p\n", INT_MIN, INT_MAX);
		chars += ft_printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
		ft_printf(" %i", chars);
	}
	return (0);
}
