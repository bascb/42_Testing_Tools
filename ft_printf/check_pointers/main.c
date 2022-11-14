#include <stdio.h>
#include "libftprintf.h"

int	main(int argc, char **argv)
{
	int		test;
	int		chars;
	char	o_path[100];
	char	f_path[100];
	FILE	*fd;
	char	c;

	c = 'a';
	if (argc < 2)
		return (0);
	test = atoi(argv[1]);
	if (test == 1)
	{
		sprintf(o_path, "check_pointers/test%i.expected", test);
		fd = freopen(o_path,"w", stdout);
		printf("Numbers: %p", &test);
		fclose(fd);
		sprintf(f_path, "check_pointers/test%i.output", test);
		fd = freopen(f_path,"w", stdout);
		ft_printf("Numbers: %p", &test);
		fclose(fd);
	}
	if (test == 2)
	{
		sprintf(o_path, "check_pointers/test%i.expected", test);
		fd = freopen(o_path,"w", stdout);
		chars = printf("Char: %p", &c);
		printf("Total: %i Pointer: %p", chars, &chars);
		fclose(fd);
		sprintf(f_path, "check_pointers/test%i.output", test);
		fd = freopen(f_path,"w", stdout);
		chars = ft_printf("Char: %p", &c);
		ft_printf("Total: %i Pointer: %p", chars, &chars);
		fclose(fd);
	}
	if (test == 3)
	{
		sprintf(o_path, "check_pointers/test%i.expected", test);
		fd = freopen(o_path,"w", stdout);
		chars = printf("NULL: %p", NULL);
		printf("Total: %i Pointer: %p", chars, &chars);
		fclose(fd);
		sprintf(f_path, "check_pointers/test%i.output", test);
		fd = freopen(f_path,"w", stdout);
		chars = ft_printf("NULL: %p", NULL);
		ft_printf("Total: %i Pointer: %p", chars, &chars);
		fclose(fd);
	}
	return (0);
}
