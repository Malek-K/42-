/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 20:14:01 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/12 17:33:22 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#define LIST_A "=>{cya} { A{whi}[%d] = {red} {bal}%lld{cya} }{eoc} <="
#define LIST_B "=>{yel} { B{whi}[%d] = {red} {bal}%lld{yel} }{eoc} <="

/*
**	CREATE A COPY OF THE POINTER TO THE CIRCULAR LISTS' ROOT
**	PRINT EVERY ELEMENT STARTING FROM THE 1ST UNTIL IT REACHES THE ROOT
*/

static void		ft_doprint(t_dllist *a, t_dllist *b)
{
	t_dllist	*p;
	int			i;

	p = a->next;
	i = 0;
	ft_printf("\n**** | LIST A | ****\n");
	while (p != a)
	{
		ft_printf(LIST_A, i, p->val);
		(i % 5 == 0) ? ft_printf("\n") : 0;
		p = p->next;
		i++;
	}
	ft_printf("\n*\v**\v***\f**** | A->LENGTH = %d | ****\n\n", a->length);
	p = b->next;
	i = 0;
	ft_printf("\n**** | LIST B | ****\n");
	while (p != b)
	{
		ft_printf(LIST_B, i, p->val);
		(i % 5 == 0) ? ft_printf("\n") : 0;
		p = p->next;
		i++;
	}
	ft_printf("\n*\v**\v***\f**** | B->LENGTH = %d | ****\n\n", b->length);
}

/*
**	PROPOSE TO PRINT THE LIST ONCE IT WENT THROUGH THE COMMAND LINES
**	THROUGH A GET NEXT LINE ON THE STANDARD ENTRY
*/

void			ft_printlists(t_dllist *a, t_dllist *b)
{
	int			i;
	char		*line;

	line = NULL;
	ft_printf("PRESS 'P' THEN ENTER TO PRINT THE LISTS\n");
	i = get_next_line(1, &line);
	if (*line && i == 1 && \
	(ft_strchr("Pp", line[0]) != NULL && ft_strchr("\0\n", line[1]) != NULL))
		ft_doprint(a, b);
	ft_strdel(&line);
}
