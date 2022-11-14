#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("A simple equation: %s", "correct");
	if (test == 2)
		printf("Two simple equations: %s %s", "ABC", "DEF");
	if (test == 3)
		printf("Joining>%s%s%s%s", "A", " day", "in my", "life!");
	return (0);
}
