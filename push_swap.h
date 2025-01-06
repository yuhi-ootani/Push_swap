/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:16:51 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 17:17:57 by oyuhi            ###   ########.fr       */
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

// main
void				error_free(char **argv, int argc, t_list *a);
void				free_all(char **argv, int argc, t_list *a);

// a
char				**ft_split_ifrom1(char const *s, char c);

// b
long				atol_numeric_only(const char *nptr);
int					stack_init(t_list **a, char **argv);
t_list				*ft_lstlast(t_list *lst);

// c
int					invalid_stack(t_list *a);

#endif