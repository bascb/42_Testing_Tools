#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("Numbers: %i%d%i%d%i", 1, 2, 3, 4, 5);
	if (test == 2)
		printf("%c%i%d%%", 'a', 34, 38);
	if (test == 3)
		printf("Joining>%c%c%s%s%i%d%%", 'a', 'b', "in my", "life!", 120, -321);
	return (0);
}
