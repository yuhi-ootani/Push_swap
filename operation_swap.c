/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_swap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:40:26 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 19:23:43 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **head)
{
	t_list	*first;
	t_list	*second;

	if (!head || !(*head) || !((*head)->next))
		return ;
	first = *head;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*head = second;
	second->prev = NULL;
	first->prev = second;
	if (first->next)
		first->next->prev = first;
}
