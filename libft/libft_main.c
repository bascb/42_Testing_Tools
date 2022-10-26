#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "libft.h"

void	test_strlen(void);
void	test_bzero(void);
void	test_memset(void);
void	test_memcpy(void);
void	test_memmove(void);
void	test_calloc(void);
void	test_strdup(void);
void	test_strlcpy(void);
void	test_strlcat(void);
void	test_toupper(void);
void	test_tolower(void);

void	test_is(int (*lib)(int), int (*ft)(int), char *ft_name)
{
	int	i;
	int	r_lib;
	int	r_ft;
	int	correct;

	printf("%s vs ft_%s:", ft_name, ft_name);
	i = -3;
	correct = 1;
	while (i < 256)
	{
		r_lib = lib(i);
		r_ft = ft(i);
		if ((r_lib && !r_ft) || (!r_lib && r_ft))
		{
			printf("Error! ");
			printf("%i %c lib: %i ft:%i\n", i, i, r_lib, r_ft);
			correct = 0;
		}
		i++;
	}
	if (correct)
		printf(" OK!\n");
}

int	main(void)
{
	test_is(isalpha, ft_isalpha, "isalpha");
	test_is(isdigit, ft_isdigit, "isdigit");
	test_is(isalnum, ft_isalnum, "isalnum");
	test_is(isascii, ft_isascii, "isascii");
	test_is(isprint, ft_isprint, "isprint");
	test_strlen();
	test_bzero();
	test_memset();
	test_memcpy();
	test_memmove();
	test_calloc();
	test_strdup();
	test_strlcpy();
	test_strlcat();
	test_toupper();
	test_tolower();
	return (0);
}