/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_push.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 07:27:25 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/08 13:53:35 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **dest, t_list **src)
{
	t_list	*pushed_lst;

	if (!*src)
		return ;
	pushed_lst = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	pushed_lst->next = *dest;
	if (*dest)
		(*dest)->prev = pushed_lst;
	pushed_lst->prev = NULL;
	*dest = pushed_lst;
}

void	pa(t_list **a, t_list **b)
{
	push(a, b);
	write(1, "pa\n", 3);
}

void	pb(t_list **b, t_list **a)
{
	push(b, a);
	write(1, "pb\n", 3);
}
