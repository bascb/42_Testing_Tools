#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include "libft.h"

void	check_number(unsigned int nbr, char *base, int test)
{
	int	fd;
	char	path[100];

	sprintf(path, "ft_putunsigned_base_fd/test%i.output", test);

	fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return ;
	ft_putunsigned_base_fd(nbr, base, fd);
	close(fd);
}

int	main(void)
{	
	check_number(1, "0123456789", 1);
	check_number(321, "0123456789", 2);
	check_number(UINT_MAX, "0123456789", 3);
	check_number(0, "0123456789", 4);
	check_number(42267, "0123456789", 5);
	check_number(1170, "0123456789", 6);
	check_number(1, "01", 7);
	check_number(321, "01", 8);
	check_number(UINT_MAX, "01", 9);
	check_number(0, "01", 10);
	check_number(1, "0123456789ABCDEF", 11);
	check_number(321, "0123456789ABCDEF", 12);
	check_number(UINT_MAX, "0123456789ABCDEF", 13);
	check_number(0, "0123456789ABCDEF", 14);
	check_number(1, "1", 15);
	check_number(3, "0123456789AABCDEF", 16);
	check_number(3, "0123456789A\nBCDEF", 17);
	check_number(1022, "0123456789", 18);
	check_number(1022, "01", 19);
	check_number(1022, "0123456789ABCDEF", 20);
	return (0);
}