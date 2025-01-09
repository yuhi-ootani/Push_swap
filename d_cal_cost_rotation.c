/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   d_cal_cost_rotation.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 14:32:01 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 16:05:51 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_abs(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

t_best_rt	cal_cost_rdrs(t_list **dest, t_list **src, long nbr, int asc)
{
	t_best_rt	tmp;

	tmp.nbr = nbr;
	tmp.dest_rt = find_best_dest(*dest, nbr, asc);
	tmp.src_rt = find_index(*src, nbr);
	if (tmp.dest_rt > tmp.src_rt)
		tmp.cost = tmp.dest_rt;
	else
		tmp.cost = tmp.src_rt;
	return (tmp);
}

t_best_rt	cal_cost_rrdrrs(t_list **dest, t_list **src, long nbr, int asc)
{
	t_best_rt	tmp;

	tmp.nbr = nbr;
	tmp.dest_rt = find_best_dest(*dest, nbr, asc) - ft_lstsize(*dest);
	tmp.src_rt = find_index(*src, nbr) - ft_lstsize(*src);
	if (ft_abs(tmp.dest_rt) > ft_abs(tmp.src_rt))
		tmp.cost = ft_abs(tmp.dest_rt);
	else
		tmp.cost = ft_abs(tmp.src_rt);
	return (tmp);
}

t_best_rt	cal_cost_rdrrs(t_list **dest, t_list **src, long nbr, int asc)
{
	t_best_rt	tmp;

	tmp.nbr = nbr;
	tmp.dest_rt = find_best_dest(*dest, nbr, asc);
	tmp.src_rt = find_index(*src, nbr) - ft_lstsize(*src);
	tmp.cost = ft_abs(tmp.dest_rt) + ft_abs(tmp.src_rt);
	return (tmp);
}

t_best_rt	cal_cost_rrdrs(t_list **dest, t_list **src, long nbr, int asc)
{
	t_best_rt	tmp;

	tmp.nbr = nbr;
	tmp.dest_rt = find_best_dest(*dest, nbr, asc) - ft_lstsize(*dest);
	tmp.src_rt = find_index(*src, nbr);
	tmp.cost = ft_abs(tmp.dest_rt) + ft_abs(tmp.src_rt);
	return (tmp);
}
