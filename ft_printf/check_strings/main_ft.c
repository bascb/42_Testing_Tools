#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		ft_printf("A simple equation: %s", "correct");
	if (test == 2)
		ft_printf("Two simple equations: %s %s", "ABC", "DEF");
	if (test == 3)
		ft_printf("Joining>%s%s%s%s", "A", " day", "in my", "life!");
	if (test == 4)
		ft_printf(" NULL %s NULL ", NULL);
	return (0);
}
