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
	return (0);
}
