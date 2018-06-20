/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mini_sortb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 17:53:52 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/07 16:13:01 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_deal_three_elem(t_dllist *a, t_dllist *b, int i)
{
	ft_sort_three_inb(a, b, i);
	PA;
	PA;
	PA;
	RA;
	RA;
	RA;
	a->sortednb += 3;
}

static void		ft_deal_two(t_dllist *a, t_dllist *b, int i)
{
	VAL_B1 == b->med ? SB : 0;
	PA;
	PA;
	RA;
	RA;
	a->sortednb += 2;
}

/*
**	SORT B WHEN THERE ARE 3 ELEMENTS OR LESS ON IT
**	DEFINE THE MED AS THE MIN VALUE VALUE IF 2 ELEMENTS
**	SORT B SO THE BIGGEST IS ON ITS TOP, THEN PUSH ALL ELEMENTS AND FINALLY
**	PUT IT BELOW STACK A USING AS MANY RA AS THERE ARE ELEMENTS ON B.
**	FINALLY INCREMENT THE INDEX OF SORTED ELEMENTS.
*/

void			ft_mini_sortb(t_dllist *a, t_dllist *b, int i)
{
	if (b->length != 0)
		b->med = (VAL_B0 <= VAL_B1) ? VAL_B0 : VAL_B1;
	if (b->length == 3)
		ft_deal_three_elem(a, b, i);
	else if (b->length == 2)
		ft_deal_two(a, b, i);
	else if (b->length == 1)
	{
		PA;
		RA;
		a->sortednb += 1;
	}
}
