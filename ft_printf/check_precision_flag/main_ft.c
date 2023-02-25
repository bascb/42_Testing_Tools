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
		chars = ft_printf("Int: %.10i %+5.10i % 5.10i %-100.10i %.10i %+.10i % 35.10i %+55.10i\n", 23, 55, 75, -23, 0, 0, 0, 0);
		chars += ft_printf("1 %.1d %.3d %.8d %.9d\n", 0, -99, INT_MAX, INT_MIN);
		chars += ft_printf("2 %08.5i\n", 34);
		chars += ft_printf("3 %.0i\n", 0);
		chars += ft_printf("4 %.i\n", 0);
		chars += ft_printf("5 %5.0i\n", 0);
		chars += ft_printf("6 %5.i\n", 0);
		chars += ft_printf("7 %5.4i\n", 0);
		chars += ft_printf("8 %013.i\n", -1488496170);
		chars += ft_printf("9 %.i\n", -1488496170);
		ft_printf(" %i", chars);
	}
	if (test == 2)
	{
		chars = ft_printf("Uns: %.10u %30.10u %-20.10u", 23, 130, 55);
		chars += ft_printf("Uns: %.1u %.2u %.1u %.12u", 0, -1, -99, UINT_MAX);
		ft_printf(" %i", chars);
	}
	if (test == 3)
	{
		chars = ft_printf("Hex: %.10x %-10.X %.10x %55.10x", 23, 420, -23, 0);
		ft_printf(" %i", chars);
	}
	if (test == 4)
	{
		chars = ft_printf("s: %100.10s %.20s\n", "ab", "cd");
		chars += ft_printf("%.s %.1s %.s %.s %.1s %.s %10.s  %.1s\n", "", "", "", "-", "2", "3", "more", "-");
		ft_printf(" %i", chars);
	}
	if (test == 5)
	{
		chars = ft_printf("1 %.3s %.2s\n", " - ", "");
		chars += ft_printf("2 %.1s %.2s %.3s %.4s\n", " - ", "", "4", "");
		chars += ft_printf("3 %.2s %.3s %.4s %.5s %.1s\n", " - ", "", "4", "", "2 ");
		chars += ft_printf("4 %.2s\n", NULL);
		chars += ft_printf("5 %.s\n", NULL);
		chars += ft_printf("6 %20.s\n", NULL);
		chars += ft_printf("7 %.2s\n", "NULL");
		chars += ft_printf("8 %.09s\n", NULL);
		chars += ft_printf("9 %3.6s\n", NULL);
		chars += ft_printf("10 %20.6s\n", NULL);
		chars += ft_printf("11 %-3.8s\n", NULL);
		chars += ft_printf("12 %-10.8s\n", NULL);
		ft_printf(" %i", chars);
	}
	if (test == 6)
	{
		chars = ft_printf("p: %.20p %40.20p", INT_MAX, INT_MAX);
		ft_printf(" %i", chars);
	}
	return (0);
}
