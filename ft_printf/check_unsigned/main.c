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
		printf("Numbers: %u%u%u%u%i", 1, 2, 3, 4, 5);
	if (test == 2)
		printf("%c%u%d%%", 'a', 34, 38);
	if (test == 3)
		printf("Joining>%c%c%s%s%u%d%%", 'a', 'b', "in my", "life!", 120, -321);
	if (test == 4)
	{
		chars = printf("%s%c%i%d%u", "Teste", 'a', 130, -20, 300);
		printf(" %i", chars);
	}
	return (0);
}
