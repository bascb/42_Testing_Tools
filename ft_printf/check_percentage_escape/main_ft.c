#include <stdio.h>
#include "ft_printf.h"

int	main(int argc, char **argv)
{
	int	test;

	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
		ft_printf("abcdefghij%%mnopqrstuvwxyz");
	if (test == 2)
		ft_printf("abcdefghijklmnokkpqrstuvw%%xyz");
	if (test == 3)
		ft_printf("abcdefghijklmnok%%%%pqrstuvwxyz");
	if (test == 4)
		ft_printf(" %-5% ");
	if (test == 5)
		ft_printf(" %% % %%");
	if (test == 6)
		ft_printf(" %-10.5% ");
	return (0);
}
