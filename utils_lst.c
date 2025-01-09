/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_lst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 08:45:00 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 10:29:51 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size++;
		lst = lst->next;
	}
	return (size);
}

int	max_nbr(t_list *lst)
{
	int	max;

	max = INT_MIN;
	if (!lst)
		return (INT_MIN);
	while (lst)
	{
		if (lst->nbr > max)
			max = lst->nbr;
		lst = lst->next;
	}
	return (max);
}

int	min_nbr(t_list *lst)
{
	int	min;

	min = INT_MAX;
	if (!lst)
		return (INT_MAX);
	while (lst)
	{
		if (lst->nbr < min)
			min = lst->nbr;
		lst = lst->next;
	}
	return (min);
}
