#include <stdio.h>
#include <string.h>
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