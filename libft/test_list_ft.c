#include <stdio.h>
#include <string.h>
#include "libft.h"

t_list	*test_lstnew(void *content)
{	
	t_list	*new;
	int		errors;

	errors = 0;
	new = ft_lstnew(content);
	if (!new)
	{
		printf("ft_lstnew: Error on memory allocation\n");
		return (NULL);
	}
	if (new->next)
	{
		printf("ft_lstnew: node next pointer not NULL\n");
		printf("	new->next = %p\n", new->next);
		errors++;
	}
	if (new->content != content)
	{
		printf("ft_lstnew: node content pointer not pointing to content address\n");
		printf("	new->content = %p\n", new->content);
		printf("	content address= %p\n", content);
		errors++;
	}
	if (!errors)
		printf("ft_lstnew: OK!\n");
	else
		printf("Found %i errors in ft_lstnew\n", errors);
	return (new);
}

void	test_lstadd_front(t_list **lst, t_list *node)
{
	int		num_list[3] = {1, 2, 3};
	int		errors;
	int		i;
	t_list	*aux;

	errors = 0;
	ft_lstadd_front(lst, node);
	if (*lst != node)
	{
		printf("lstadd_front: Error! List not pointing to node\n");
		printf("	List pointing to: %p\n", *lst);
		printf("	node Pointer: %p\n", node);
		errors++;
	}
	aux = *lst;
	i = 0;
	while (aux)
	{
		if (*(int *) aux->content != num_list[i])
		{
			printf("lstadd_front: Error! List with wrong order\n");
			printf("	Expected number: %i\n", num_list[i]);
			printf("	Node content number: %i\n", *(int *) aux->content);
			errors++;
		}
		i++;
		aux = aux->next;
	};
	if (!errors)
		printf("ft_lstadd_front: OK!\n");
	else
		printf("Found %i errors in ft_lstadd_front\n", errors);
}

void	test_lstadd_back(t_list **lst, t_list *node)
{
	int		num_list[4] = {1, 2, 3, 4};
	int		errors;
	int		i;
	t_list	*aux;

	errors = 0;
	ft_lstadd_back(lst, node);
	aux = *lst;
	i = 0;
	while (aux)
	{
		if (*(int *) aux->content != num_list[i])
		{
			printf("lstadd_back: Error! List with wrong order\n");
			printf("	Expected number: %i\n", num_list[i]);
			printf("	Node content number: %i\n", *(int *) aux->content);
			errors++;
		}
		i++;
		aux = aux->next;
	};
	if (!errors)
		printf("ft_lstadd_back: OK!\n");
	else
		printf("Found %i errors in ft_lstadd_back\n", errors);
}

void	test_lstsize(t_list *lst, int expected)
{
	int	errors;
	int	count;

	errors = 0;
	count = ft_lstsize(lst);
	if (count != expected)
	{
		printf("ft_lstsize: Error!\n");
		printf("	Expected count: %i\n", expected);
		printf("	ft_lstsize returned value: %i\n", count);
		errors++;
	}
	if (!errors)
		printf("ft_lstsize: OK!\n");
	else
		printf("Found %i errors in ft_lstsize\n", errors);
}

void	test_lstlast(t_list *lst, int expected)
{
	t_list	*last;
	int		errors;

	errors = 0;
	last = ft_lstlast(lst);
	if (!last)
	{
		printf("ft_lstlast: Error! Returned NULL pointer!\n");
		return ;
	}
	if (*(int *) last->content != expected)
	{
		printf("ft_lstlast: Error! Returned content value don't match expected!\n");
		printf("	Expected: %i\n", expected);
		printf("	Content value: %i\n", *(int *) last->content);
		errors++;
	}
	if (!errors)
		printf("ft_lstlast: OK!\n");
	else
		printf("Found %i errors in ft_lstlast\n", errors);
}

void	all_list_tests(void)
{
	t_list	**lst;
	t_list	*node_1;
	t_list	*node_2;
	t_list	*node_3;
	t_list	*node_4;
	int		number_1;
	int		number_2;
	int		number_3;
	int		number_4;

	lst = malloc(sizeof(t_list *));
	*lst = NULL;
	number_1 = 1;
	number_2 = 2;
	number_3 = 3;
	number_4 = 4;
	node_1 = test_lstnew(&number_1);
	node_2 = ft_lstnew(&number_2);
	node_3 = ft_lstnew(&number_3);
	node_4 = ft_lstnew(&number_4);
	ft_lstadd_back(lst, node_3);
	ft_lstadd_front(lst, node_2);
	test_lstadd_front(lst, node_1);
	test_lstadd_back(lst, node_4);
	test_lstsize(*lst, 4);
	test_lstlast(*lst, 4);
	free(lst);
	free(node_1);
	free(node_2);
	free(node_3);
	free(node_4);
}
