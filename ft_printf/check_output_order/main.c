#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("abcdefghijklmnopqrstuvwxyz");
	return (0);
}
