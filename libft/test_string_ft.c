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
	printf("%s: lib: %zi ft: %zi diff: %zi ", label, r_lib, r_ft, diff);
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
		printf("	strlcpy: %zu\n", lib_len);
		printf("	ft_strlcpy: %zu\n", ft_len);
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
		printf("	size: %zu\n", size);
		printf("	src_len: %zu\n", ft_strlen(src));
		printf("	strlcat: %zu\n", lib_len);
		printf("	ft_strlcat: %zu\n", ft_len);
		printf("	string: %s\n", src);
		errors++;
	}
	if (strcmp(l_buffer, f_buffer))
	{
		printf("strlcat vs ft_strlcat: Error! Copy don't match\n");
		printf("	size: %zu\n", size);
		printf("	src_len: %zu\n", ft_strlen(src));
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
		printf("	n: %zu\n", n);
		errors++;
	}
	if ((l_cmp > 0 && f_cmp <= 0) || (l_cmp <= 0 && f_cmp >0))
	{
		printf("strncmp vs ft_strncmp: Error!\n");
		printf("	strncmp: %i\n", l_cmp);
		printf("	ft_strncmp: %i\n", f_cmp);
		printf("	string1: %s\n", s1);
		printf("	string2: %s\n", s2);
		printf("	n: %zu\n", n);
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
	errors += check_strncmp("2", "23", 2);
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
		printf("	n: %zu\n", n);
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
	ft = ft_atoi(str);
	if (lib != ft)
	{
		printf("atoi vs ft_atoi: Error! Numbers don't match\n");
		printf("	atoi: %i\n", lib);
		printf("	ft_atoi: %i\n", ft);
		printf("	number string: %s\n", str);
		errors++;
	}
	return (errors);
}

void	test_atoi(void)
{
	int	errors;

	errors = 0;
	errors += check_atoi("123");
	errors += check_atoi("321");
	errors += check_atoi("	321");
	errors += check_atoi("	+321");
	errors += check_atoi("	-321");
	errors += check_atoi("a321");
	errors += check_atoi("4500s345");
	errors += check_atoi("	--321");
	errors += check_atoi("2147483647");
	errors += check_atoi("-2147483648");
	errors += check_atoi("2147483648");
	errors += check_atoi("2147483650");
	errors += check_atoi("-2147483649");
	errors += check_atoi("-2147483650");
	errors += check_atoi("\e475");
	errors += check_atoi("");
	if (!errors)
		printf("atoi vs ft_atoi: OK!\n");
	else
		printf("Found %i errors in ft_atoi\n", errors);
}

int	check_substr(char *str, unsigned int start, size_t len)
{
	char	*new;
	int		errors;
	size_t	diff;

	errors = 0;
	new = ft_substr(str, start, len);
	if (!new)
	{
		printf("ft_substr: Error on memory allocation!\n");
		return (1);
	}
	if ((size_t) start >= ft_strlen(str))
	{
		if (ft_strlen(new))
		{
			printf("ft_substr: Error! start index exceeds str size!\n");
			printf("	Original str: %s\n", str);
			printf("	Original str size: %zu\n", ft_strlen(str));
			printf("	New str: %s\n", new);
			printf("	New str: %zu\n", ft_strlen(new));
			printf("	start index: %u : len: %zu\n", start, len);
			free(new);
			return (1);
		}
		else
		{
			free(new);
			return (0);
		}
 	}
	diff = ft_strncmp(new, &str[start], len);
	if (diff)
	{
		printf("ft_substr: Error! Comparisation do not match\n");
		printf("	Comparisation diff: %zu\n", diff);
		printf("	Original str: %s\n", str);
		printf("	Original substr: %.*s\n", (int) len, &str[start]);
		printf("	New str: %s\n", new);
		printf("	start index: %u : len: %zu\n", start, len);
		errors++;
	}
	free(new);
	return (errors);
}

void	test_substr(void)
{
	int	errors;

	errors = 0;
	errors += check_substr("123", 0, 2);
	errors += check_substr("123", 1, 2);
	errors += check_substr("123", 1, 1);
	errors += check_substr("123", 2, 1);
	errors += check_substr("123", 0, 3);
	errors += check_substr("123", 0, 4);
	errors += check_substr("", 0, 4);
	errors += check_substr("123", 0, 0);
	errors += check_substr("123", 2, 0);
	errors += check_substr("", 0, 0);
	errors += check_substr("abdefg", 1, 2);
	errors += check_substr("abdefg", 6, 2);
	errors += check_substr("abdefg", 8, 2);
	errors += check_substr("lorem ipsum dolor sit amet", 400, 20);
	if (!errors)
		printf("ft_substr: OK!\n");
	else
		printf("Found %i errors in ft_substr\n", errors);
}

int	check_strjoin(char *s1, char *s2)
{
	char	*new;
	char	compare[strlen(s1) + strlen(s2) + 1];
	int		errors;
	size_t	diff;

	strlcpy(compare, s1, strlen(s1) + strlen(s2) + 1);
	strlcat(compare, s2, strlen(s1) + strlen(s2) + 1);
	errors = 0;
	new = ft_strjoin(s1, s2);
	if (!new)
	{
		printf("ft_strjoin: Error on memory allocation!\n");
		return (1);
	}
	diff = ft_strncmp(new, compare, strlen(s1) + strlen(s2));
	if (diff)
	{
		printf("ft_strjoin: Error! Comparisation do not match\n");
		printf("	Comparisation diff: %zu\n", diff);
		printf("	s1: %s\n", s1);
		printf("	s2: %s\n", s2);
		printf("	reference join string: %s\n", compare);
		printf("	ft_strjoin string: %s\n", new);
		errors++;
	}
	free(new);
	return (errors);
}

void	test_strjoin(void)
{
	int	errors;

	errors = 0;
	errors += check_strjoin("abc", "def");
	errors += check_strjoin("ab", "de");
	if (!errors)
		printf("ft_strjoin: OK!\n");
	else
		printf("Found %i errors in ft_strjoin\n", errors);

}

int	check_strtrim(char *s1, char *set, char *expected)
{
	char	*new;
	int		errors;
	size_t	diff;
	size_t	max;

	errors = 0;
	max = strlen(expected);
	new = ft_strtrim(s1, set);
	if (strlen(new) > max)
		max = strlen(new);
	if (!new)
	{
		printf("ft_strtrim: Error on memory allocation!\n");
		return (1);
	}
	diff = strncmp(new, expected, max);
	if (diff)
	{
		printf("ft_strtrim: Error! Comparisation do not match\n");
		printf("	Comparisation diff: %zu\n", diff);
		printf("	ft_strtrim string: %s\n", new);
		printf("	expected string: %s\n", expected);
		printf("	s1 string: %s\n", s1);
		printf("	set string: %s\n", set);
		errors++;
	}
	free(new);
	return (errors);
}

void	test_strtrim(void)
{
	int	errors;

	errors = 0;
	errors += check_strtrim("lorem \n ipsum \t dolor \n sit \t amet", "	", "lorem \n ipsum \t dolor \n sit \t amet");
	errors += check_strtrim("lorem ipsum dolor sit amet", "te", "lorem ipsum dolor sit am");
	errors += check_strtrim("abc", "a", "bc");
	errors += check_strtrim("abc", "z", "abc");
	errors += check_strtrim("abc", "b", "abc");
	errors += check_strtrim("abc", "c", "ab");
	errors += check_strtrim("", "c", "");
	errors += check_strtrim("abc", "", "abc");
	errors += check_strtrim("aaaaaaaaaaaaaaabcdd", "ad", "bc");
	errors += check_strtrim("aacc", "ac", "");
	if (!errors)
		printf("ft_strtrim: OK!\n");
	else
		printf("Found %i errors in ft_strtrim\n", errors);
}

void	check_split(char *str, char c)
{
	char	**strings;
	int		i;

	printf("Original string:\n%s\n", str);
	printf("Delimiter char: %c\n", c);
	strings = ft_split(str, c);
	i = 0;
	while (strings[i])
	{
		printf("%s\n", strings[i]);
		free(strings[i]);
		i++;
	}
	free(strings);
}

void	test_split(void)
{
	check_split("cbacdc", 'c');
	check_split("acbcd", 'c');
	check_split("cbacd", 'c');
	check_split("cbacdc", 'c');
	check_split("cbacdce", 'c');
	check_split("cccccc", 'c');
	check_split("", 'z');
	check_split("  lorem   ipsum dolor     sit amet, consectetur   adipiscing elit. Sed non risus. Suspendisse   ", ' ');
	check_split("lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed non risus. Suspendisse lectus tortor, dignissim sit amet, adipiscing nec, ultricies sed, dolor. Cras elementum ultricies diam. Maecenas ligula massa, varius a, semper congue, euismod non, mi.", 'z');
}

int	check_itoa(int n, char *expected)
{
	char	*number;
	int		errors;

	errors = 0;
	number = ft_itoa(n);
	if (!number)
	{
		printf("ft_itoa: Error! NULL pointer!\n");
		printf("	ft_itoa pointer: %p\n", number);
		return (1);
	}
	if (strcmp(expected, number))
	{
		printf("ft_itoa: Error! Numbers don't match!\n");
		printf("	Expected: %s\n", expected);
		printf("	Returned: %s\n", number);
		errors++;
	}
	free(number);
	return (errors);
}

void	test_itoa(void)
{
	int	errors;

	errors = 0;
	errors += check_itoa(123, "123");
	errors += check_itoa(-123, "-123");
	errors += check_itoa(-1557, "-1557");
	errors += check_itoa(INT_MAX, "2147483647");
	errors += check_itoa(INT_MIN, "-2147483648");
	errors += check_itoa(2147483648, "-2147483648");
	if (!errors)
		printf("ft_itoa: OK!\n");
	else
		printf("Found %i errors in ft_itoa\n", errors);
}

char	map_str(unsigned int i, char c)
{
	if (!i && islower(c))
		return (ft_toupper(c));
	if (i && isupper(c))
		return (ft_tolower(c));
	return (c);
}

int	check_strmapi(char *s, char *expected)
{
	char	*new;
	int		errors;

	errors = 0;
	new = ft_strmapi(s, map_str);
	if (!new)
	{
		printf("ft_strmapi: Error! NULL pointer!\n");
		printf("	ft_strmapi pointer: %p\n", new);
		return (1);
	}
	if (strcmp(expected, new))
	{
		printf("ft_strmapi: Error! Results don't match!\n");
		printf("	Expected: %s\n", expected);
		printf("	Returned: %s\n", new);
		errors++;
	}
	free(new);
	return (errors);
}

void	test_strmapi(void)
{
	int	errors;

	errors = 0;
	errors += check_strmapi("adEus", "Adeus");
	errors += check_strmapi("certo", "Certo");
	errors += check_strmapi("cLARO", "Claro");
	if (!errors)
		printf("ft_strmapi: OK!\n");
	else
		printf("Found %i errors in ft_strmapi\n", errors);
}

void	map_str_2(unsigned int i, char *c)
{
	if (!i && islower(*c))
		*c = ft_toupper(*c);
	if (i && isupper(*c))
		*c = ft_tolower(*c);
}

int	check_striteri(char *s, char *expected)
{
	int		errors;

	errors = 0;
	ft_striteri(s, map_str_2);
	if (strcmp(expected, s))
	{
		printf("ft_striteri: Error! Results don't match!\n");
		printf("	Expected: %s\n", expected);
		printf("	Iterated: %s\n", s);
		errors++;
	}
	return (errors);
}

void	test_striteri(void)
{
	int		errors;
	char	a[] = "adEus";
	char	b[] = "certo";
	char	c[] = "cLARO";

	errors = 0;
	errors += check_striteri(a, "Adeus");
	errors += check_striteri(b, "Certo");
	errors += check_striteri(c, "Claro");
	if (!errors)
		printf("ft_striteri: OK!\n");
	else
		printf("Found %i errors in ft_striteri\n", errors);
}
