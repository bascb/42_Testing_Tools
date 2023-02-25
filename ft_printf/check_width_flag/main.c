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
		chars = printf("Int: %10i %1i", 23, 100);
		printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = printf("Uns: %10u %10u", 23, -10);
		printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = printf("Hex: %10x %10X %1x", 120, 120, 120);
		printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = printf("Char: %10c %1c", 'a', 'b');
		printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = printf("String: %10s %1s", "ases", "grandes!!");
		printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = printf("Int: %+10i %+1i", 23, 100);
		printf(" %i", chars);
	}
	if (test == 7)
	{
		chars = printf("Int: %+10i %1i", 0, 0);
		printf(" %i", chars);
	}
	if (test == 8)
	{
		chars = printf("%197c %-1c", 7, 120);
		printf(" %i", chars);
	}
	if (test == 9)
	{
		chars = printf("%12p", (void*)18229185041105221837lu);
		printf(" %i", chars);
	}
	if (test == 10)
	{
		chars = printf("8 %013i\n", -1488496170);
		printf(" %i", chars);
	}
	return (0);
}
