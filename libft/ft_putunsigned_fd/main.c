#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <limits.h>
#include "libft.h"

void	check_number(int nbr, int test)
{
	int	fd;
	char	path[100];

	sprintf(path, "ft_putunsigned_fd/test%i.output", test);

	fd = open(path, O_RDWR | O_CREAT, 0644);
	if (fd < 0)
		return ;
	ft_putunsigned_fd(nbr, fd);
	close(fd);
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