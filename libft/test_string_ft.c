#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <bsd/string.h>
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

int	sub_test_strdup(char *str)
{
	char	*lib;
	char	*ft;
	int		errors;

	errors = 0;
	lib = strdup(str);
	ft = ft_strdup(str);
	if ((!lib && ft) || (lib && !ft))
	{
		printf("strdup vs ft_strdup: Error! NULL vs no NULL\n");
		printf("	strdup: %p\n", lib);
		printf("	ft_strdup: %p\n", ft);
		printf("	string: %s\n", str);
		errors++;
	}
	if (strcmp(lib, ft))
	{
		printf("strdup vs ft_strdup: Error! Duplicate don't match\n");
		printf("	strdup: %s\n", lib);
		printf("	ft_strdup: %s\n", ft);
		errors++;
	}
	free(lib);
	free(ft);
	return (errors);
}

void	test_strdup(void)
{
	char	empty[] = "";
	char	great[] = "Thank you 42!";
	char	weird[5] = {'a', 49, -4, 'b', '\0'};
	int		errors;

	errors = 0;
	errors += sub_test_strdup(empty);
	errors += sub_test_strdup(weird);
	errors += sub_test_strdup(great);
	if (!errors)
		printf("strdup vs ft_strdup: OK!\n");
	else
		printf("Found %i errors in ft_strdup\n", errors);
}

int	sub_test_strlcpy(char *src, size_t size)
{
	int		errors;
	size_t	lib_len;
	size_t	ft_len;
	char	l_buffer[size];
	char	f_buffer[size];

	memset(l_buffer, 0, size);
	memset(f_buffer, 0, size);
	errors = 0;
	lib_len = strlcpy(l_buffer, src, size);
	ft_len = ft_strlcpy(f_buffer, src, size);
	if (lib_len != ft_len)
	{
		printf("strlcpy vs ft_strlcpy: Error! Returned size don't match\n");
		printf("	strlcpy: %lu\n", lib_len);
		printf("	ft_strlcpy: %lu\n", ft_len);
		printf("	string: %s\n", src);
		errors++;
	}
	if (strcmp(l_buffer, f_buffer))
	{
		printf("strlcpy vs ft_strlcpy: Error! Copy don't match\n");
		printf("	strlcpy: %s\n", l_buffer);
		printf("	ft_strlcpy: %s\n", f_buffer);
		errors++;
	}
	return (errors);
}

void	test_strlcpy(void)
{
	char	empty[] = "";
	char	great[] = "Thank you 42!";
	char	weird[5] = {'a', 49, -4, 'b', '\0'};
	int		errors;

	errors = 0;
	errors += sub_test_strlcpy(empty, 0);
	errors += sub_test_strlcpy(weird, 5);
	errors += sub_test_strlcpy(great, 6);
	if (!errors)
		printf("strlcpy vs ft_strlcpy: OK!\n");
	else
		printf("Found %i errors in ft_strlcpy\n", errors);
}

int	sub_test_strlcat(char *src, size_t size)
{
	int		errors;
	size_t	lib_len;
	size_t	ft_len;
	char	l_buffer[size];
	char	f_buffer[size];

	memset(l_buffer, 0, size);
	memset(f_buffer, 0, size);
	
	if (size > 1)
	{
		memset(l_buffer, 49, size - 1);
		memset(f_buffer, 49, size - 1);
	}
	errors = 0;
	lib_len = strlcat(l_buffer, src, size);
	ft_len = ft_strlcat(f_buffer, src, size);
	if (lib_len != ft_len)
	{
		printf("strlcat vs ft_strlcat: Error! Returned size don't match\n");
		printf("	size: %lu\n", size);
		printf("	src_len: %lu\n", ft_strlen(src));
		printf("	strlcat: %lu\n", lib_len);
		printf("	ft_strlcat: %lu\n", ft_len);
		printf("	string: %s\n", src);
		errors++;
	}
	if (strcmp(l_buffer, f_buffer))
	{
		printf("strlcat vs ft_strlcat: Error! Copy don't match\n");
		printf("	size: %lu\n", size);
		printf("	src_len: %lu\n", ft_strlen(src));
		printf("	strlcat: %s\n", l_buffer);
		printf("	ft_strlcat: %s\n", f_buffer);
		printf("	string: %s\n", src);
		errors++;
	}
	return (errors);
}

void	test_strlcat(void)
{
	char	empty[] = "";
	char	great[] = "Thank you 42!";
	char	weird[5] = {'a', 49, -4, 'b', '\0'};
	int		errors;

	errors = 0;
	errors += sub_test_strlcat(empty, 100);
	errors += sub_test_strlcat(weird, 100);
	errors += sub_test_strlcat(great, 100);
	if (!errors)
		printf("strlcat vs ft_strlcat: OK!\n");
	else
		printf("Found %i errors in ft_strlcat\n", errors);
}

void	test_toupper(void)
{
	char	test[] = "abcEfR2zS";
	size_t	i;
	int		errors;

	errors = 0;
	i = 0;
	while (i < strlen(test))
	{
		if (toupper(test[i]) != ft_toupper(test[i]))
		{
			printf("toupper vs ft_toupper. Error on: %c\n", test[i]);
			errors++;
		}
		i++;
	}
	if (!errors)
		printf("toupper vs ft_toupper: OK!\n");
	else
		printf("Found %i errors in ft_toupper\n", errors);
}

void	test_tolower(void)
{
	char	test[] = "abcEfR2zS";
	size_t	i;
	int		errors;

	errors = 0;
	i = 0;
	while (i < strlen(test))
	{
		if (tolower(test[i]) != ft_tolower(test[i]))
		{
			printf("tolower vs ft_tolower. Error on: %c\n", test[i]);
			errors++;
		}
		i++;
	}
	if (!errors)
		printf("tolower vs ft_tolower: OK!\n");
	else
		printf("Found %i errors in ft_tolower\n", errors);
}

int	check_strchr(char *str, int c)
{
	char	*lib;
	char	*ft;
	int		errors;

	errors = 0;
	lib = strchr(str, c);
	ft = ft_strchr(str, c);
	if (lib != ft)
	{
		printf("strchr vs ft_strchr: Error! Returned pointer don't match\n");
		printf("	strchr: %p\n", lib);
		printf("	ft_strchr: %p\n", ft);
		printf("	string: %s\n", str);
		printf("	char to find: %c\n", c);
		errors++;
	}
	if (!lib || !ft)
		return (errors);
	if (*lib != *ft)
	{
		printf("strchr vs ft_strchr: Error! Char's don't match\n");
		printf("	strchr: %c\n", *lib);
		printf("	ft_strchr: %c\n", *ft);
		printf("	string: %s\n", str);
		errors++;
	}
	return (errors);
}

void	test_strchr(void)
{
	char	str[] = "abcdeabcde";
	int		errors;

	errors = 0;
	errors += check_strchr(str, 'a');
	errors += check_strchr(str, 'b');
	errors += check_strchr(str, 'c');
	errors += check_strchr(str, 'd');
	errors += check_strchr(str, 'e');
	errors += check_strchr(str, 'z');
	errors += check_strchr(str, '\0');
	if (!errors)
		printf("strchr vs ft_strchr: OK!\n");
	else
		printf("Found %i errors in ft_strchr\n", errors);
}

int	check_strrchr(char *str, int c)
{
	char	*lib;
	char	*ft;
	int		errors;

	errors = 0;
	lib = strrchr(str, c);
	ft = ft_strrchr(str, c);
	if (lib != ft)
	{
		printf("strrchr vs ft_strrchr: Error! Returned pointer don't match\n");
		printf("	strrchr: %p\n", lib);
		printf("	ft_strrchr: %p\n", ft);
		printf("	string: %s\n", str);
		printf("	char to find: %c\n", c);
		errors++;
	}
	if (!lib || !ft)
		return (errors);
	if (*lib != *ft)
	{
		printf("strrchr vs ft_strrchr: Error! Char's don't match\n");
		printf("	strrchr: %c\n", *lib);
		printf("	ft_strrchr: %c\n", *ft);
		printf("	string: %s\n", str);
		errors++;
	}
	return (errors);
}

void	test_strrchr(void)
{
	char	str[] = "abcdeabcde";
	int		errors;

	errors = 0;
	errors += check_strrchr(str, 'a');
	errors += check_strrchr(str, 'b');
	errors += check_strrchr(str, 'c');
	errors += check_strrchr(str, 'd');
	errors += check_strrchr(str, 'e');
	errors += check_strrchr(str, 'z');
	errors += check_strrchr(str, '\0');
	if (!errors)
		printf("strrchr vs ft_strrchr: OK!\n");
	else
		printf("Found %i errors in ft_strrchr\n", errors);
}

int	check_strncmp(char *s1, char *s2, size_t n)
{
	int	errors;
	int	l_cmp;
	int f_cmp;

	errors = 0;
	l_cmp = strncmp(s1, s2, n);
	f_cmp = ft_strncmp(s1, s2, n);
	if ((!l_cmp && f_cmp) || (l_cmp && !f_cmp))
	{
		printf("strncmp vs ft_strncmp: Error!\n");
		printf("	strncmp: %i\n", l_cmp);
		printf("	ft_strncmp: %i\n", f_cmp);
		printf("	string1: %s\n", s1);
		printf("	string2: %s\n", s2);
		printf("	n: %lu\n", n);
		errors++;
	}
	if ((l_cmp > 0 && f_cmp <= 0) || (l_cmp <= 0 && f_cmp >0))
	{
		printf("strncmp vs ft_strncmp: Error!\n");
		printf("	strncmp: %i\n", l_cmp);
		printf("	ft_strncmp: %i\n", f_cmp);
		printf("	string1: %s\n", s1);
		printf("	string2: %s\n", s2);
		printf("	n: %lu\n", n);
		errors++;
	}
	return (errors);
}

void	test_strncmp(void)
{
	char	a[] = "Adeus jovens!Mais tarde";
	char	b[] = "Adeus jovens!Mais tArde";
	char	neg[] = {'A', -3, 48, 53, 243, '\0'};
	char	pos[] = {'A', 49, 48, 53, 243, '\0'};
	int		errors;

	errors = 0;
	errors += check_strncmp(a, b, 23);
	errors += check_strncmp(a, b, 10);
	errors += check_strncmp(b, b, 23);
	errors += check_strncmp(a, a, 10);
	errors += check_strncmp(b, a, 23);
	errors += check_strncmp(b, a, 10);
	errors += check_strncmp(a, neg, 5);
	errors += check_strncmp(b, neg, 5);
	errors += check_strncmp(neg, neg, 5);
	errors += check_strncmp(neg, a, 5);
	errors += check_strncmp(neg, b, 5);
	errors += check_strncmp(neg, pos, 5);
	errors += check_strncmp(a, pos, 5);
	errors += check_strncmp(b, pos, 5);
	errors += check_strncmp(pos, pos, 5);
	errors += check_strncmp(pos, neg, 5);
	errors += check_strncmp(pos, a, 5);
	errors += check_strncmp(pos, b, 5);
	errors += check_strncmp("abcdwxyz", "abcdwxyz", 4);
	errors += check_strncmp("zyxbcdefgh", "abcdwxyz", 0);
	errors += check_strncmp("abcdefgh:", "", 0);
	errors += check_strncmp("", "test", 4);
	errors += check_strncmp("test", "", 4);
	errors += check_strncmp("abcdefgh", "abcdwxyz", 4);
	if (!errors)
		printf("strncmp vs ft_strncmp: OK!\n");
	else
		printf("Found %i errors in ft_strncmp\n", errors);
}

int	check_strnstr(char *s1, char *s2, size_t n)
{
	char	*lib;
	char	*ft;
	int		errors;

	errors = 0;
	lib = strnstr(s1, s2, n);
	ft = ft_strnstr(s1, s2, n);
	if (lib != ft)
	{
		printf("strnstr vs ft_strnstr: Error! Returned pointer don't match\n");
		printf("	strnstr: %p\n", lib);
		printf("	ft_strnstr: %p\n", ft);
		printf("	s1: %s\n", s1);
		printf("	s2: %s\n", s2);
		printf("	n: %lu\n", n);
		errors++;
	}
	return (errors);
}

void	test_strnstr(void)
{
	int	errors;

	errors = 0;
	errors += check_strnstr("abcdefgh", "abcd", 4);
	errors += check_strnstr("abcdefgh", "abcd", 3);
	errors += check_strnstr("efghabcd", "abcd", 8);
	errors += check_strnstr("efghabcd", "gh", 0);
	errors += check_strnstr("efghabcd", "gh", 7);
	errors += check_strnstr("efghabcd", "xk", 8);
	errors += check_strnstr("efghabcd", "", 8);
	errors += check_strnstr("", "xk", 8);
	errors += check_strnstr("lorem ipsum dolor sit amet", "dolor", 15);
	if (!errors)
		printf("strnstr vs ft_strnstr: OK!\n");
	else
		printf("Found %i errors in ft_strnstr\n", errors);
}

int	check_atoi(char *str)
{
	int	lib;
	int	ft;
	int	errors;

	errors = 0;
	lib = atoi(str);
	ft = 0;
//	ft = ft_atoi(str);
//	if (lib != ft)
//	{
		printf("atoi vs ft_atoi: Error! Numbers don't match\n");
		printf("	atoi: %i\n", lib);
		printf("	ft_atoi: %i\n", ft);
		printf("	number string: %s\n", str);
		errors++;
//	}
	return (errors);
}

void	test_atoi(void)
{
	int	errors;

	errors = 0;
	errors += check_atoi("123");
/*	errors += check_atoi("321");
	errors += check_atoi("	321");
	errors += check_atoi("	+321");
	errors += check_atoi("	-321");
	errors += check_atoi("a321");
	errors += check_atoi("4500s345");
	errors += check_atoi("	--321");
	errors += check_atoi("2147483647");
	errors += check_atoi("-2147483648");
	errors += check_atoi("2147483648");
	errors += check_atoi("-2147483648");
	errors += check_atoi(""); */
	if (!errors)
		printf("atoi vs ft_atoi: OK!\n");
	else
		printf("Found %i errors in ft_atoi\n", errors);
}