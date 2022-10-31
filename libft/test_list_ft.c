#include <stdio.h>
#include <string.h>
#include "libft.h"

void	test_lstnew(void)
{	
	int		number;
	t_list	*new;
	int		errors;

	errors = 0;
	number = 4;
	new = ft_lstnew(&number);
	if (!new)
	{
		printf("ft_lstnew: Error on memory allocation\n");
		return ;
	}
	if (new->next)
	{
		printf("ft_lstnew: node next pointer not NULL\n");
		printf("	new->next = %p\n", new->next);
		errors++;
	}
	if (new->content != &number)
	{
		printf("ft_lstnew: node content pointer not pointing to content address\n");
		printf("	new->content = %p\n", new->content);
		printf("	content address= %p\n", &number);
		errors++;
	}
	if (!errors)
		printf("ft_lstnew: OK!\n");
	else
		printf("Found %i errors in ft_lstnew\n", errors);
}

void	all_list_tests(void)
{
	test_lstnew();
}
