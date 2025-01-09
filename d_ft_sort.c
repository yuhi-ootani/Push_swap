/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_ft_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 18:30:49 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 15:18:14 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check the lists are already sorted.
int	is_sorted(t_list *a)
{
	while (a->next)
	{
		if (a->nbr > a->next->nbr)
			return (0);
		a = a->next;
	}
	return (1);
}

// push back from stack b to stack a with sorting.
void	sort_pa_all(t_list **a, t_list **b)
{
	t_best_rt	best;
	long		min;

	while (*b)
	{
		best.cost = INT_MAX;
		find_best_rts(a, b, &best, 1);
		apply_best_rts(a, b, &best, 1);
		pa(a, b);
	}
	min = min_nbr(*a);
	if (find_index(*a, min) < ft_lstsize(*a) / 2)
	{
		while ((*a)->nbr != min)
			ra(a);
	}
	else
	{
		while ((*a)->nbr != min)
			rra(a);
	}
}

// sort and push from stack a to stack b until stack a has 3 lists.
void	sort_pb_till_3(t_list **a, t_list **b)
{
	t_best_rt	best;

	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		pb(b, a);
	if (ft_lstsize(*a) > 3 && !is_sorted(*a))
		pb(b, a);
	while (ft_lstsize(*a) > 3 && !is_sorted(*a))
	{
		best.cost = INT_MAX;
		find_best_rts(b, a, &best, 0);
		apply_best_rts(b, a, &best, 0);
		pb(b, a);
	}
	if (!is_sorted(*a))
		sort_three(a);
}

// sort only three lists
void	sort_three(t_list **a)
{
	int	max;

	if (!a || !(*a) || ft_lstsize(*a) != 3)
		return ;
	max = max_nbr(*a);
	if ((*a)->nbr == max)
		ra(a);
	else if ((*a)->next->nbr == max)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

// beginning of sort function
void	ft_sort(t_list **a, t_list **b)
{
	int	size;

	if (!a || !(*a) || !b || is_sorted(*a))
		return ;
	size = ft_lstsize(*a);
	if (size == 2)
		sa(a);
	if (size == 3)
		sort_three(a);
	else
	{
		sort_pb_till_3(a, b);
		sort_pa_all(a, b);
	}
}
