/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oyuhi <oyuhi@student.42tokyo.jp>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/05 16:37:43 by oyuhi             #+#    #+#             */
/*   Updated: 2025/01/06 17:19:29 by oyuhi            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(char **argv, int argc, t_list *a)
{
	int		i;
	t_list	*tmp;

	i = 1;
	if (argv && argc == 2)
	{
		while (argv[i])
			free(argv[i++]);
		free(argv);
	}
	if (a)
	{
		while (a)
		{
			tmp = a;
			a = a->next;
			free(tmp);
		}
	}
}

void	error_free(char **argv, int argc, t_list *a)
{
	free_all(argv, argc, a);
	write(1, "Error\n", 6);
	exit(1);
}