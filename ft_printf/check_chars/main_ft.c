#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		ft_printf("Letters: %c %c %c", 'a', 'b', 'c');
	if (test == 2)
		ft_printf("%c0%c0%c", 'a', 0, 'c');
	if (test == 3)
		ft_printf("%c%c%c%%", 'a', 49, 'c');
	if (test == 4)
		ft_printf("%c%c%c%%", 'a', 5, 'c');
	if (test == 5)
		ft_printf("Joining>%c%c%s%s%%", 'a', 'b', "in my", "life!");
	return (0);
}
