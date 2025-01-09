/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:16:51 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/09 16:06:41 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	long			nbr;
	struct s_list	*prev;
	struct s_list	*next;

}					t_list;

typedef struct s_best_rt
{
	long			nbr;
	int				cost;
	int				dest_rt;
	int				src_rt;
}					t_best_rt;

// a //
// main, free, error, split
void				error_free(char **argv, int argc, t_list *a);
void				free_all(char **argv, int argc, t_list *a);
char				**ft_split_ifrom1(char const *s, char c);

// b stack initialization, atol
int					stack_init(t_list **a, char **argv);
long				atol_numeric_only(const char *nptr);

// c check stack validation
int					invalid_stack(t_list *a);

// d start of sort, push a from b, push b from a
void				ft_sort(t_list **a, t_list **b);
int					is_sorted(t_list *a);
void				sort_three(t_list **a);
void				sort_pb_till_3(t_list **a, t_list **b);
void				sort_pa_all(t_list **a, t_list **b);

// d sort helper : find the best place to push and apply the best method.
int					find_index(t_list *lst, long nbr);
int					find_best_dest(t_list *dest, long nbr, int asc);
void				find_best_rts(t_list **dest, t_list **src, t_best_rt *best,
						int asc);
void				apply_best_rts(t_list **dest, t_list **src, t_best_rt *best,
						int acs);

// calculation sorting cost of each node
t_best_rt			cal_cost_rdrs(t_list **dest, t_list **src, long nbr,
						int asc);
t_best_rt			cal_cost_rrdrrs(t_list **dest, t_list **src, long nbr,
						int asc);
t_best_rt			cal_cost_rdrrs(t_list **dest, t_list **src, long nbr,
						int asc);
t_best_rt			cal_cost_rrdrs(t_list **dest, t_list **src, long nbr,
						int asc);

// operation
// push
void				pa(t_list **a, t_list **b);
void				pb(t_list **b, t_list **a);
// reverse rotate
void				rra(t_list **a);
void				rrb(t_list **b);
void				rrr(t_list **dest, t_list **src);
// rotate
void				ra(t_list **a);
void				rb(t_list **b);
void				rr(t_list **dest, t_list **src);
// swap
void				sa(t_list **a);
void				sb(t_list **b);
void				ss(t_list **a, t_list **b);

// utils_lst
t_list				*ft_lstlast(t_list *lst);
int					ft_lstsize(t_list *lst);
int					max_nbr(t_list *lst);
int					min_nbr(t_list *lst);
int					is_sorted(t_list *a);

// delete//
// void				print_list(t_list *head);
// # include <stdio.h>
// delete//

#endif