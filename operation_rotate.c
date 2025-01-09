/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_rotate.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:09:54 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/08 13:05:01 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_list **head)
{
	t_list	*last;
	t_list	*rotated_lst;

	if (!head || !(*head) || !(*head)->next)
		return ;
	last = ft_lstlast(*head);
	rotated_lst = *head;
	*head = (*head)->next;
	(*head)->prev = NULL;
	last->next = rotated_lst;
	rotated_lst->next = NULL;
	rotated_lst->prev = last;
}

void	ra(t_list **a)
{
	rotate(a);
	write(1, "ra\n", 3);
}

void	rb(t_list **b)
{
	rotate(b);
	write(1, "rb\n", 3);
}

void	rr(t_list **dest, t_list **src)
{
	rotate(dest);
	rotate(src);
	write(1, "rr\n", 3);
}

// #include <stdio.h>
// #include <stdlib.h>

// // Helper functions
// t_list	*create_node(int value)
// {
// 	t_list	*node;

// 	node = malloc(sizeof(t_list));
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
// 	// Print original list
// 	printf("Original list: ");
// 	print_list(head);
// 	// Rotate the list
// 	ra(&head);
// 	// Print rotated list
// 	printf("Rotated list: ");
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
