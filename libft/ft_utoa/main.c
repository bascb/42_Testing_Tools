#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include "libft.h"

void	check_number(unsigned int nbr, int test)
{
	int	fd;
	char	path[100];
	char	*number;

	sprintf(path, "ft_utoa/test%i.output", test);

	fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return ;
	number = ft_utoa(nbr);
	ft_putstr_fd(number, fd);
	close(fd);
	free(number);
}

int	main(void)
{	
	check_number(1, 1);
	check_number(0, 2);
	check_number(UINT_MAX, 3);
	check_number(45532, 4);
	check_number(42267, 5);
	return (0);
}
