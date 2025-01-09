/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_reverse_rotate.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:59:41 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 09:46:46 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **head)
{
	t_list	*last;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = ft_lstlast(*head);
	last->prev->next = NULL;
	last->prev = NULL;
	last->next = *head;
	(*head)->prev = last;
	(*head) = last;
}

void	rra(t_list **a)
{
	reverse_rotate(a);
	write(1, "rra\n", 4);
}

void	rrb(t_list **b)
{
	reverse_rotate(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_list **dest, t_list **src)
{
	reverse_rotate(dest);
	reverse_rotate(src);
	write(1, "rrr\n", 4);
}

// #include <stdio.h>
// #include <stdlib.h>

// t_list	*create_node(int value)
// {
// 	t_list	*node;

// 	node = (t_list *)malloc(sizeof(t_list));
// 	if (!node)
// 		return (NULL);
// 	node->nbr = value;
// 	node->next = NULL;
// 	node->prev = NULL;
// 	return (node);
// }

// void	print_list(t_list *head)
// {
// 	while (head)
// 	{
// 		printf("%ld ", head->nbr);
// 		head = head->next;
// 	}
// 	printf("\n");
// }

// t_list	*ft_lstlast(t_list *head)
// {
// 	while (head && head->next)
// 		head = head->next;
// 	return (head);
// }
// int	main(void)
// {
// 	t_list	*head;
// 	t_list	*temp;

// 	// Create a list: 1 -> 2 -> 3 -> NULL
// 	head = create_node(1);
// 	head->next = create_node(2);
// 	head->next->prev = head;
// 	head->next->next = create_node(3);
// 	head->next->next->prev = head->next;
// 	printf("Original list: ");
// 	print_list(head);
// 	// Perform reverse rotation
// 	reverse_rotate(&head);
// 	printf("After reverse rotate: ");
// 	print_list(head);
// 	// Free memory
// 	while (head)
// 	{
// 		temp = head;
// 		head = head->next;
// 		free(temp);
// 	}
// 	return (0);
// }
