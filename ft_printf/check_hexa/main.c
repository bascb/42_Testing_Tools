#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	test;
	int	chars;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		printf("Numbers: %u%u%u%x%X", 1, 2, 3, 4, 5);
	if (test == 2)
		printf("%c%X%x%%", 'a', 34, 38);
	if (test == 3)
		printf("Joining>%c%c%s%s%x%X%%", 'a', 'b', "in my", "life!", 120, -321);
	if (test == 4)
	{
		chars = printf("%X%x", -20, 300);
		printf(" %i", chars);
	}
	return (0);
}
