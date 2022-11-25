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
		chars = printf("Int: %.10i %+5.10i % 5.10i %-100.10i %.10i %+.10i % 35.10i %+55.10i\n", 23, 55, 75, -23, 0, 0, 0, 0);
		chars += printf("%.1d %.3d %.8d %.9d", 0, -99, INT_MAX, INT_MIN);
		printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = printf("Uns: %.10u %30.10u %-20.10u", 23, 130, 55);
		chars += printf("Uns: %.1u %.2u %.1u %.12u", 0, -1, -99, UINT_MAX);
		printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = printf("Hex: %.10x %-10.X %.10x %55.10x", 23, 420, -23, 0);
		printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = printf("s: %100.10s %.20s\n", "ab", "cd");
		chars += printf("%.s %.1s %.s %.s %.1s %.s %10.s  %.1s\n", "", "", "", "-", "2", "3", "more", "-");
		printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = printf("1 %.3s %.2s\n", " - ", "");
		chars += printf("2 %.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
		chars += printf("3 %.2s %.3s %.4s %.5s %.1s\n", " - ", "", "4", "", "2 ");
		printf(" %i", chars);
	}
	return (0);
}
