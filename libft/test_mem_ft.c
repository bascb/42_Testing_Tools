#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_bzero(void)
{
	char	buffer_a[10];
	char	buffer_b[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		buffer_a[i] = i + 1;
		buffer_b[i] = i + 2;
		i++;
	}
	bzero(buffer_a, 10);
	ft_bzero(buffer_b, 10);
	if (!strcmp(buffer_a, buffer_b))
		printf("bzero vs ft_bzero: OK!\n");
	else
		printf("bzero vs ft_bzero: Error!\n");
}

void	test_memset(void)
{
	char	buffer_a[10];
	char	buffer_b[10];
	int		i;

	i = 0;
	while (i < 10)
	{
		buffer_a[i] = i + 1;
		buffer_b[i] = i + 2;
		i++;
	}
	memset(buffer_a, 0, 10);
	ft_memset(buffer_b, 0, 10);
	if (!strcmp(buffer_a, buffer_b))
		printf("memset vs ft_memset: OK!\n");
	else
	{
		printf("memset vs ft_memset: Error!\n");
		printf("	memset: %s\n", buffer_a);
		printf("	ft_memset: %s\n", buffer_b);
	}
}

void	test_memcpy(void)
{
	char	buffer_a[10];
	char	buffer_b[10];
	char	buffer_s[10];
	int		i;

	memset(buffer_a, 0, 10);
	memset(buffer_b, 0, 10);
	memset(buffer_s, 0, 10);
	i = 0;
	while (i < 10)
	{
		buffer_s[i] = i + 1;
		i++;
	}
	memcpy(buffer_a, buffer_s, 10);
	ft_memcpy(buffer_b, buffer_s, 10);
	if (!strncmp(buffer_a, buffer_b, 10))
		printf("memcpy vs ft_memcpy: OK!\n");
	else
	{
		printf("memcpy vs ft_memcpy: Error!\n");
		printf("	memcpy: %s\n", buffer_a);
		printf("	ft_memcpy: %s\n", buffer_b);
	}
}

void	test_memmove(void)
{
	char	buffer_a[20];
	char	buffer_b[20];
	char	*buffer_s;
	int		i;

	memset(buffer_a, 0, 20);
	memset(buffer_b, 0, 20);
	buffer_s = &buffer_a[11];
	memset(buffer_s, 0, 10);
	i = 0;
	while (i < 10)
	{
		buffer_s[i] = i + 1;
		i++;
	}
	memmove(buffer_a, buffer_s, 10);
	buffer_s = &buffer_b[11];
	memset(buffer_s, 0, 10);
	i = 0;
	while (i < 10)
	{
		buffer_s[i] = i + 1;
		i++;
	}
	ft_memmove(buffer_b, buffer_s, 10);
	if (!strncmp(buffer_a, buffer_b, 20))
		printf("memmove vs ft_memmove: OK!\n");
	else
	{
		printf("memmove vs ft_memmove: Error!\n");
		printf("	memmove: %s\n", buffer_a);
		printf("	ft_memmove: %s\n", buffer_b);
	}
}

void	test_calloc(void)
{
	char	*lib;
	char	*ft;
	int		errors;

	errors = 0;
	lib = calloc(0, 1);
	ft = ft_calloc(0, 1);
	if ((!lib && ft) || (lib && !ft))
	{
		printf("calloc vs ft_calloc: Error! nmeb = 0\n");
		printf("	calloc: %p\n", lib);
		printf("	ft_calloc: %p\n", ft);
		errors++;
	}
	free(lib);
	free(ft);

	lib = calloc(2, 0);
	ft = ft_calloc(2, 0);
	if ((!lib && ft) || (lib && !ft))
	{
		printf("calloc vs ft_calloc: Error! size = 0\n");
		printf("	calloc: %p\n", lib);
		printf("	ft_calloc: %p\n", ft);
		errors++;
	}
	free(lib);
	free(ft);

	lib = calloc(10, 1);
	ft = ft_calloc(10, 1);
	if (memcmp(lib, ft, 10))
	{
		printf("calloc vs ft_calloc: Error! calloc != ft_calloc\n");
		printf("	calloc: %s\n", (char *) lib);
		printf("	ft_calloc: %s\n", (char *) ft);
		errors++;
	}
	free(lib);
	free(ft);
	if (!errors)
		printf("calloc vs ft_calloc: OK!\n");
	else
		printf("Found %i errors in ft_calloc\n", errors);
}