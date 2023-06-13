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
		chars = printf("Int: %010i %08i %08i", 23, 34, -34);
		printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = printf("Uns: %010u", 23);
		printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = printf("Hex: %010x", 23);
		printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = printf("Hex: %010x", -23);
		printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = printf("Int: %010i", -23);
		printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = printf("Int: %+010i", 23);
		printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = printf("Int: %010i %+010i", 0, 0);
		printf(" %i", chars);
	}
	if (test == 8)
	{
		chars = printf("P: %010p", INT_MAX);
		printf(" %i", chars);
	}
	return (0);
}
