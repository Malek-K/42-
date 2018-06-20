/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 17:45:15 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/12 17:28:09 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_list_sorted(t_dllist *a)
{
	t_dllist	*tmp;

	tmp = a->next;
	while (tmp->next != a)
	{
		if (tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
	}
	return (0);
}

/*
**	LOOK INSIDE EVERY ARGUMENT FOR AN OPTION (-C/V/Q/Z)
**	RETURN INT VALUE DEPENDING ON THEIR PRESENCE
*/

static int		ft_check_op(int argc, char **argv, int *q, int *z)
{
	int		x;
	int		y;
	int		c;
	int		v;

	x = 1;
	c = 0;
	v = 0;
	while (x < argc)
	{
		y = 0;
		while (argv[x][y])
		{
			argv[x][y] == 'c' ? c = 1 : 0;
			argv[x][y] == 'v' ? v = 3 : 0;
			argv[x][y] == 'q' ? *q = 1 : 0;
			argv[x][y] == 'z' ? *z = 1 : 0;
			y++;
		}
		x++;
	}
	return (c + v);
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
**	FIRST CHECK IF OPTIONS: PRINT COMMAND IN COLORS (-C),  PRINT LISTS (-V),
**	SORT USING QUICKSORT ONLY (-Q), PRINT NUMBER OF MOVES (-Z)
**	IF -V, CHANGE THE VALUE OF A->PRINT AND PRINT THE LISTS AT START/END
**	THEN SORT DEPENDING ON THE NUMBER OF ARGUMENTS, AND OPTION -Q OR NOT
**	SORT_LITTLE FOR 2-3 NUMBERS
**	SORT_MIDLLE FOR 4-6 NUMBERS
**	REAL_SORT (MIX OF QUICKSORT & INSERTION SORT) FOR MORE THAN 6,
**	OR JUST QUICKSORT IF OPTION -Q
*/

static void		ft_print_n_sort(int argc, char **argv, t_dllist *a, t_dllist *b)
{
	int			j;
	int			q;
	int			z;

	j = 1;
	q = 0;
	z = 0;
	a->moves = 0;
	if (ft_check_op(argc, argv, &q, &z) == 1 || \
			ft_check_op(argc, argv, &q, &z) == 4)
		j = 2;
	if (ft_check_op(argc, argv, &q, &z) == 3 || \
			ft_check_op(argc, argv, &q, &z) == 4)
		a->print = 1;
	a->print == 1 ? ft_printf("\n**** | LISTS AT START | ****\n") : 0;
	a->print == 1 ? ft_printlists(a, b) : 0;
	a->length < 4 ? ft_sort_little(a, b, j) : 0;
	(a->length >= 4 && a->length < 7) ? ft_sort_medium(a, b, j) : 0;
	if (a->length >= 7)
		q == 0 ? ft_real_sort(a, b, j) : ft_quick_sort(a, b, j);
	a->print == 1 ? ft_printf("\n**** | LISTS AT END | ****\n") : 0;
	a->print == 1 ? ft_printlists(a, b) : 0;
	z != 0 ? ft_printf("NUMBER OF MOVES : %d\n", a->moves) : 0;
}

/*
**	DIFFERENT STEPS OF THE MAIN
**	0 - USAGE IF NOT ENOUGH ARGUMENTS
**	1 - CHECK IF ERRORS, IF NONE PUT ARGUMENTS IN LIST A, ELSE ERROR ON FD 2
**	2 - IF LIST IS SORTED, DO NOTHING, ELSE CONTINUE
**	3 - CHECK IF OPTIONS AND SORT LIST A
**	4 - FREE THE LISTS AND RETURN
*/

int				main(int argc, char **argv)
{
	t_dllist	*a;
	t_dllist	*b;

	a = NULL;
	b = NULL;
	if (argc < 2)
		return (0);
	else
	{
		if (ft_check_errors(argc, argv, &a, &b) == -1)
		{
			ft_putendl_fd("Error", 2);
			return (0);
		}
		else if (ft_list_sorted(a) != 0)
			ft_print_n_sort(argc, argv, a, b);
		ft_free_list(a);
		ft_free_list(b);
	}
	return (0);
}
