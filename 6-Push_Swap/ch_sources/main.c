/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:45:15 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/12 21:19:32 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#define WARNING "Be Aware : List is already sorted !\n"

static int		ft_list_sorted(t_dllist *a, t_dllist *b)
{
	t_dllist	*tmp;

	tmp = a->next;
	if (a->next == a || b->length != 0)
		return (-1);
	while (tmp->next != a)
	{
		if (tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

static void		ft_free_list(t_dllist *a)
{
	t_dllist	*tmp;
	t_dllist	*tmp2;

	tmp = a->next;
	while (tmp != a)
	{
		tmp2 = tmp->next;
		free(tmp);
		tmp = NULL;
		tmp = tmp2;
	}
	free(a);
	a = NULL;
}

/*
**	DIFFERENT STEPS OF THE MAIN
**	1 - CHECK IF ERRORS, IF NONE PUT ARGUMENTS IN LIST A
**	2 - PRINT A WARINING IF LIST IS SORTED
**	3 - CHECK AND DO THE COMMAND MOVES IF THEY ARE CORRECT
**	4 - PRINT OK IF FINAL STATE IS SORTED, ELSE KO
**	5 - SUGGESTION TO PRINT THE LISTS IN FINAL STATE
**	6 - FREE THE LISTS AND RETURN
*/

int				main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;
	int			j;

	a = NULL;
	b = NULL;
	j = 0;
	if (argc < 2)
		return (0);
	else
	{
		if (ft_check_errors(argc, argv, &a, &b) == -1)
			ft_putendl_fd("Error", 2);
		else
		{
			ft_list_sorted(a, b) == 0 ? ft_printf(WARNING) : 0;
			ft_moves(a, b, j) == -2 ? ft_printf("FINAL COMMAND!\n") : 0;
			ft_list_sorted(a, b) == 0 ? ft_printf("OK\n") : 0;
			ft_list_sorted(a, b) != 0 ? ft_putendl_fd("KO", 2) : 0;
			ft_printlists(a, b);
			ft_free_list(a);
			ft_free_list(b);
		}
	}
	return (0);
}
