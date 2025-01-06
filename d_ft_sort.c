/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:30:49 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 18:39:36 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	int	num;

	num = 0;
	while (lst)
	{
		num++;
		lst = lst->next;
	}
	return (num);
}

void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !(*a) || !b)
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
    
    
}
