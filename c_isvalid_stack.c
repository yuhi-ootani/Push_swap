/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   c_isvalid_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 16:28:04 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 09:44:48 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check non numeric, too big, too small nbr by INT_MAX and INT_MIN
// find dupulication by bubble sort
// if find invalid nbr return 1 as error
int	invalid_stack(t_list *a)
{
	t_list	*tmp;

	while (a)
	{
		if (a->nbr > INT_MAX || a->nbr < INT_MIN)
			return (1);
		tmp = a->next;
		while (tmp)
		{
			if (a->nbr == tmp->nbr)
				return (1);
			tmp = tmp->next;
		}
		a = a->next;
	}
	return (0);
}
