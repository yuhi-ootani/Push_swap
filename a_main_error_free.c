/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_main_error_free.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 15:48:14 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 16:05:19 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **argv, int argc, t_list *a)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (argv && argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (a)
	{
		while (a)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
	}
}

void	error_free(char **argv, int argc, t_list *a)
{
	free_all(argv, argc, a);
	write(1, "Error\n", 6);
	exit(1);
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
	ft_sort(&a, &b);
	free_all(argv, argc, a);
	return (0);
}

//*************comments out *************/
// #include <stdio.h>

// void	print_list(t_list *head)
// {
// 	t_list	*current;

// 	current = head;
// 	while (current != NULL)
// 	{
// 		printf("%ld -> ", current->nbr);
// 		current = current->next;
// 	}
// 	printf("NULL\n");
// }
