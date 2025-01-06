/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a1_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:48:14 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 18:31:17 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
// delete
#include <stdio.h>

void	print_list(t_list *head)
{
	t_list	*current;

	current = head;
	while (current != NULL)
	{
		printf("%ld -> ", current->nbr);
		// Print the  of the current node
		current = current->next; // Move to the next node
	}
	printf("NULL\n"); // Indicate the end of the list
}

int	issort(t_list *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

// Original argv:
// Provided by the operating system.
// Does not need to be freed.
int	main(int argc, char **argv)
{
	int		error_flag;
	t_list	*a;
	t_list	*b;

	error_flag = 0;
	a = NULL;
	b = NULL;
	if (argc == 1)
		return (0);
	else if (argc == 2)
		argv = ft_split_ifrom1(&argv[1][0], ' ');
	error_flag = stack_init(&a, argv);
	if (invalid_stack(a) || !argv || error_flag)
		error_free(argv, argc, a);
	if (!issort(a))
		ft_sort(&a, &b);
	free_all(argv, argc, a);
	return (0);
}
