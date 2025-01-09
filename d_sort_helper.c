/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_sort_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/09 10:11:50 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 16:12:37 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// find the index of the list which stores nbr and return the value
int	find_index(t_list *lst, long nbr)
{
	int	i;

	i = 0;
	while (lst->nbr != nbr)
	{
		i++;
		lst = lst->next;
	}
	return (i);
}

// find an index number in the destination stack where it should be inserted.
// return 0 means it should be inserted between first and last list.
int	find_best_dest(t_list *dest, long nbr, int asc)
{
	int		i;
	t_list	*later;

	i = 1;
	if (nbr < min_nbr(dest) || nbr > max_nbr(dest))
	{
		if (asc)
			return (find_index(dest, min_nbr(dest)));
		else
			return (find_index(dest, max_nbr(dest)));
	}
	later = dest->next;
	while (dest->next)
	{
		if ((asc && (dest->nbr < nbr && nbr < later->nbr)) || (!asc
				&& (dest->nbr > nbr && nbr > later->nbr)))
			return (i);
		dest = dest->next;
		later = dest->next;
		i++;
	}
	return (0);
}
// if ((asc && nbr < dest->nbr && nbr > ft_lstlast(dest)->nbr) || (!asc
// 			&& nbr > dest->nbr && nbr < ft_lstlast(dest)->nbr))
// 		return (0);

// check four pair of rotation cobination (rdrs ,rrdrrs, rdrrs, rrdrs)
// and decide which rotation cobination is the best.
void	find_best_rts(t_list **dest, t_list **src, t_best_rt *best, int asc)
{
	t_list		*tmp;
	t_best_rt	candidate;

	tmp = *src;
	while (tmp)
	{
		candidate = cal_cost_rdrs(dest, src, tmp->nbr, asc);
		if (best->cost > candidate.cost)
			(*best) = candidate;
		candidate = cal_cost_rrdrrs(dest, src, tmp->nbr, asc);
		if (best->cost > candidate.cost)
			(*best) = candidate;
		candidate = cal_cost_rdrrs(dest, src, tmp->nbr, asc);
		if (best->cost > candidate.cost)
			(*best) = candidate;
		candidate = cal_cost_rrdrs(dest, src, tmp->nbr, asc);
		if (best->cost > candidate.cost)
			(*best) = candidate;
		tmp = tmp->next;
	}
}

// apply rotation until both dest_rt and src_rt become 0
void	apply_best_rts(t_list **dest, t_list **src, t_best_rt *best, int acs)
{
	int	d;
	int	s;

	d = best->dest_rt;
	s = best->src_rt;
	while (d > 0 && s > 0 && d-- && s--)
		rr(dest, src);
	while (d < 0 && s < 0 && d++ && s++)
		rrr(dest, src);
	while (!acs && best->src_rt > 0 && s > 0 && s--)
		ra(src);
	while (acs && best->dest_rt > 0 && d > 0 && d--)
		ra(dest);
	while (!acs && best->dest_rt > 0 && d > 0 && d--)
		rb(dest);
	while (acs && best->src_rt > 0 && s > 0 && s--)
		rb(src);
	while (!acs && best->src_rt < 0 && s < 0 && s++)
		rra(src);
	while (acs && best->dest_rt < 0 && d < 0 && d++)
		rra(dest);
	while (!acs && best->dest_rt < 0 && d < 0 && d++)
		rrb(dest);
	while (acs && best->src_rt < 0 && s < 0 && s++)
		rrb(src);
}
// printf("dest:%d  src:%d\n", best->dest_rt, best->src_rt);
// printf("d:%d  s:%d\n", d, s);
