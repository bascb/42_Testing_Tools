#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		ft_printf("abcdefghijklmnopqrstuvwxyz");
	if (test == 2)
		ft_printf("abcdefghijklmnokkpqrstuvwxyz");
	if (test == 3)
		ft_printf("abcdefghijklmnok\n\tpqrstuvwxyz");
	return (0);
}
