#include <stdio.h>
#include <string.h>
#include "libft.h"

void	print_strlen(char *str, char *label)
{
	size_t	diff;
	size_t	r_lib;
	size_t	r_ft;

	r_lib = strlen(str);
	r_ft = ft_strlen(str);
	diff = r_lib - r_ft;
	printf("%s: lib: %li ft: %li diff: %li ", label, r_lib, r_ft, diff);
	if (!diff)
		printf("OK\n");
	else
		printf("Error!\n");
}

void	test_strlen(void)
{
	char	empty[] = "";
	char	no_terminator[] = {'a', 'c'};
	char	correct[] = "Testing strlen";

	print_strlen(empty, "strlen with empty string");
	print_strlen(no_terminator, "strlen without terminator");
	print_strlen(correct, "strlen with terminated string");
}