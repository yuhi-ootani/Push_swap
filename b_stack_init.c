/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_stack_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 13:56:43 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 19:01:48 by oyuhi            ###   ########.fr       */
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

// if malloc failed, it will be invalied in isvalid_stack function.
int	stack_init(t_list **a, char **argv)
{
	int		i;
	t_list	*new;

	if (!a || !argv)
		return (1);
	i = 1;
	while (argv[i])
	{
		new = (t_list *)malloc(sizeof(t_list));
		if (!new)
			return (1);
		new->nbr = atol_numeric_only(argv[i]);
		new->prev = NULL;
		new->next = NULL;
		if (!*a)
			*a = new;
		else
		{
			new->prev = (ft_lstlast(*a));
			new->prev->next = new;
		}
		i++;
	}
	return (0);
}
