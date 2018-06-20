/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/02 13:55:06 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 17:18:10 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

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
**	CREATION OF THE ARRAY IN HARD CODE ONCE IT IS ALLOCATED
**	ASSOCIATES THE FUNTIONS TO THE EXACT STRING COMMAND
*/

static void		ft_create_movtab(t_funky_mov *tab)
{
	tab[0].mov = "pa";
	tab[0].ptrmov = &ft_pa;
	tab[1].mov = "pb";
	tab[1].ptrmov = &ft_pb;
	tab[2].mov = "sa";
	tab[2].ptrmov = &ft_sa;
	tab[3].mov = "sb";
	tab[3].ptrmov = &ft_sb;
	tab[4].mov = "ss";
	tab[4].ptrmov = &ft_ss;
	tab[5].mov = "ra";
	tab[5].ptrmov = &ft_ra;
	tab[6].mov = "rb";
	tab[6].ptrmov = &ft_rb;
	tab[7].mov = "rr";
	tab[7].ptrmov = &ft_rr;
	tab[8].mov = "rra";
	tab[8].ptrmov = &ft_rra;
	tab[9].mov = "rrb";
	tab[9].ptrmov = &ft_rrb;
	tab[10].mov = "rrr";
	tab[10].ptrmov = &ft_rrr;
	tab[11].mov = NULL;
	tab[11].ptrmov = NULL;
}

/*
**	CHECKING IF COMMAND IS A CORRECT ONE, MEANING CONTAINED IN THE ARRAY
**	IF NOT, FREE ARRAY AND LINE, PRINT ERROR MESSAGE ON FD 2
**	AND EXIT WITH ERROR INT : 1
*/

static void		ft_invalid_command(char *line, t_funky_mov *movtab, \
		t_dllist *a, t_dllist *b)
{
	if (*line != EOF)
	{
		ft_putendl_fd("Error", 2);
		free(movtab);
		ft_strdel(&line);
		ft_free_list(a);
		ft_free_list(b);
		ft_printf("!!! NOT A VALID COMMAND !!!\n");
		exit(1);
	}
}

/*
**	MALLOC A TAB OF FUNCTIONS FOR EACH MOVING FUNCTIONS
**	APPLY THE FUNCTION CORRESPONDING TO THE COMMAND, FREE ARRAY  AND RETURN 0
**	IF COMMAND IS NOT A CORRECT ONE, ENTERS INVALID COMMAND AND PRINT ERROR
*/

static int		ft_show_me_your_moves(char *line, t_dllist *a, t_dllist *b, \
		int x)
{
	int			i;
	t_funky_mov *movtab;

	i = 0;
	if (!(movtab = (t_funky_mov *)malloc(sizeof(*movtab) * 12)))
		return (-1);
	ft_create_movtab(movtab);
	while (movtab[i].mov != NULL)
	{
		if (ft_strcmp(movtab[i].mov, line) == 0)
		{
			movtab[i].ptrmov(a, b, x);
			free(movtab);
			return (0);
		}
		i++;
	}
	ft_invalid_command(line, movtab, a, b);
	return (-1);
}

/*
**	THROUGH A LOOP, TAKES THE COMMAND LINES LINE FROM PUSH_SWAP FROM STD EXIT
**	USING GET_NEXT_LINE TAKE THE COMMAND, GET THE ACTUAL LINE OF COMMAND
**	APPLY THE MOVES THOURGH FT_SHOW_MOVES
**	FREE THE LINE USED IN GNL
**	DEPENDING ON THE RETURN FROM SHOW_MOVES, RETURN INT VALUE TO MAIN FUNCTION
*/

int				ft_moves(t_dllist *a, t_dllist *b, int x)
{
	char		*line;
	int			i;
	int			j;

	i = 2;
	j = 0;
	line = NULL;
	while (i != 0)
	{
		i = get_next_line(0, &line);
		if (i == 0 || i == -1)
		{
			ft_strdel(&line);
			return (i == 0) ? 0 : -1;
		}
		j = ft_show_me_your_moves(line, a, b, x);
		ft_strdel(&line);
		if (j == -1)
			return (-2);
		i++;
	}
	return (0);
}
