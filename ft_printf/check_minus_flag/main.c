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
		chars = printf("Int: %-10i %-10i", 23, -23);
		printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = printf("Uns: %-10u", 23);
		printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = printf("Hex: %-10x %-10X", 120, 120);
		printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = printf("Char: %-10c", 'a');
		printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = printf("String: %-10s", "ases");
		printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = printf(" %-1c %-2c %-3c ", '0', 0, '1');
		printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = printf(" %-11p %-12p\n", INT_MIN, INT_MAX);
		chars += printf(" %-13p %-14p ", ULONG_MAX, -ULONG_MAX);
		printf(" %i", chars);
	}
	return (0);
}
