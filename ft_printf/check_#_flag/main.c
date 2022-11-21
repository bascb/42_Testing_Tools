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
		chars = printf("Hexa: %#x %#X %#x %#X %#x %#X", 420, 420, -110, -110, 0, 0);
		printf(" %i", chars);
	}
	return (0);
}
