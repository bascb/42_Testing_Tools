#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("abcdefghij%%mnopqrstuvwxyz");
	if (test == 2)
		printf("abcdefghijklmnokkpqrstuvw%%xyz");
	if (test == 3)
		printf("abcdefghijklmnok%%%%pqrstuvwxyz");
	return (0);
}
