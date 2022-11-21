#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("Letters: %c %c %c", 'a', 'b', 'c');
	if (test == 2)
		printf("%c0%c0%c", 'a', 0, 'c');
	if (test == 3)
		printf("%c%c%c%%", 'a', 49, 'c');
	if (test == 4)
		printf("%c%c%c%%", 'a', 5, 'c');
	if (test == 5)
		printf("Joining>%c%c%s%s%%", 'a', 'b', "in my", "life!");
	return (0);
}
