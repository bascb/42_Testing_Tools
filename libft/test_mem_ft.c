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
	if (!memcmp(buffer_a, buffer_b, 10))
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
	buffer_s = &buffer_a[10];
	memset(buffer_s, 0, 10);
	i = 0;
	while (i < 10)
	{
		buffer_s[i] = i + 1;
		i++;
	}
	memmove(buffer_a, buffer_s, 10);
	buffer_s = &buffer_b[10];
	memset(buffer_s, 0, 10);
	i = 0;
	while (i < 10)
	{
		buffer_s[i] = i + 1;
		i++;
	}
	ft_memmove(buffer_b, buffer_s, 10);
	if (!memcmp(buffer_a, buffer_b, 20))
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

int	check_memchr(char *buf, int c, size_t n)
{
	void	*lib;
	void	*ft;
	int		errors;

	errors = 0;
	lib = memchr(buf, c, n);
	ft = ft_memchr(buf, c, n);
	if (lib != ft)
	{
		printf("memchr vs ft_memchr: Error! Returned pointer don't match\n");
		printf("	memchr: %p\n", lib);
		printf("	ft_memchr: %p\n", ft);
		printf("	string: %s\n", buf);
		printf("	char to find: %c\n", c);
		printf("	n: %zu\n", n);
		errors++;
	}
	if (!lib || !ft)
		return (errors);
	if (*(char *) lib != *(char *) ft)
	{
		printf("memchr vs ft_memchr: Error! Char's don't match\n");
		printf("	memchr: %c\n", *(char *) lib);
		printf("	ft_memchr: %c\n", *(char *) ft);
		printf("	string: %s\n", buf);
		printf("	n: %zu\n", n);
		errors++;
	}
	return (errors);
}

void	test_memchr(void)
{
	char	str[] = "abcdeabcde";
	int		errors;

	errors = 0;
	errors += check_memchr(str, 'a', 10);
	errors += check_memchr(str, 'b', 10);
	errors += check_memchr(str, 'c', 10);
	errors += check_memchr(str, 'd', 10);
	errors += check_memchr(str, 'e', 10);
	errors += check_memchr(str, 'z', 10);
	errors += check_memchr(str, '\0', 10);
	if (!errors)
		printf("memchr vs ft_memchr: OK!\n");
	else
		printf("Found %i errors in ft_memchr\n", errors);
}

int	check_memcmp(char *s1, char *s2, size_t n)
{
	int	errors;
	int	l_cmp;
	int f_cmp;

	errors = 0;
	l_cmp = memcmp(s1, s2, n);
	f_cmp = ft_memcmp(s1, s2, n);
	if ((!l_cmp && f_cmp) || (l_cmp && !f_cmp))
	{
		printf("memcmp vs ft_memcmp: Error!\n");
		printf("	memcmp: %i\n", l_cmp);
		printf("	ft_memcmp: %i\n", f_cmp);
		printf("	string1: %s\n", s1);
		printf("	string2: %s\n", s2);
		printf("	n: %zu\n", n);
		errors++;
	}
	if ((l_cmp > 0 && f_cmp <= 0) || (l_cmp <= 0 && f_cmp >0))
	{
		printf("memcmp vs ft_memcmp: Error!\n");
		printf("	memcmp: %i\n", l_cmp);
		printf("	ft_memcmp: %i\n", f_cmp);
		printf("	string1: %s\n", s1);
		printf("	string2: %s\n", s2);
		printf("	n: %zu\n", n);
		errors++;
	}
	return (errors);
}

void	test_memcmp(void)
{
	char	a[] = "Adeus jovens!Mais tarde";
	char	b[] = "Adeus jovens!Mais tArde";
	char	neg[] = {'A', -3, 48, 53, 243, '\0'};
	char	pos[] = {'A', 49, 48, 53, 243, '\0'};
	int		errors;

	errors = 0;
	errors += check_memcmp(a, b, 23);
	errors += check_memcmp(a, b, 10);
	errors += check_memcmp(b, b, 23);
	errors += check_memcmp(a, a, 10);
	errors += check_memcmp(b, a, 23);
	errors += check_memcmp(b, a, 10);
	errors += check_memcmp(a, neg, 5);
	errors += check_memcmp(b, neg, 5);
	errors += check_memcmp(neg, neg, 5);
	errors += check_memcmp(neg, a, 5);
	errors += check_memcmp(neg, b, 5);
	errors += check_memcmp(neg, pos, 5);
	errors += check_memcmp(a, pos, 5);
	errors += check_memcmp(b, pos, 5);
	errors += check_memcmp(pos, pos, 5);
	errors += check_memcmp(pos, neg, 5);
	errors += check_memcmp(pos, a, 5);
	errors += check_memcmp(pos, b, 5);
	errors += check_memcmp("abcdwxyz", "abcdwxyz", 4);
	errors += check_memcmp("zyxbcdefgh", "abcdwxyz", 0);
	errors += check_memcmp("abcdefgh:", "", 0);
	errors += check_memcmp("", "test", 4);
	errors += check_memcmp("test", "", 4);
	errors += check_memcmp("abcdefgh", "abcdwxyz", 4);
	if (!errors)
		printf("memcmp vs ft_memcmp: OK!\n");
	else
		printf("Found %i errors in ft_memcmp\n", errors);
}
