/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_medium.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 17:16:14 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/12 16:21:44 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_rrss(t_dllist *a, t_dllist *b, int i, int j)
{
	RRA;
	j == 2 ? SS : SA;
}

static void		ft_sortb_with_a_little_l(t_dllist *a, t_dllist *b, int i)
{
	if (VAL_B1 > VAL_B2)
	{
		if (!(VAL_B2 > VAL_B0))
		{
			if (VAL_B1 < VAL_B0)
				RRB;
			else
			{
				SB;
				RB;
			}
		}
	}
	else
	{
		if (!(VAL_B1 < VAL_B0 && \
					VAL_B2 > VAL_B0))
		{
			SB;
			(VAL_B2 < VAL_B0 && VAL_B1 < VAL_B0) ? RRB : 0;
		}
		else
			RB;
	}
}

/*
**	STEPS TO DEAL WITH FIVE ELEMS :
**	1 - PUSH THE 2 MINIMUM VALUES ON STACK B, AND RA UNTILL STARTING MEDIAN IS
**		EITHER AT TOP OR BOTTOM OF STACK A. WHEN THE 2 MINIMUMS ARE PUSHED ON B,
**		THIS MEDIAN IS ACTUALLY THE MINIMUM IN STACK A.
**	2 - SORTING STACK B IS EASY, AS THERE ARE ONLY 2 VALUES. SORTING STACK A
**		JUST MEANS FINDING WHICH ONE OF THE TWO VALUES DIFFERENT FROM MEDIAN IS
**		THE SMALLEST AND REORGANISE IT THROUGH FT_RRSS.
**	3 - PUSH BACK ON STACK A WHEN B IS SORTED IN DECREASING ORDER.
*/

static void		ft_deal_five(t_dllist *a, t_dllist *b, int i)
{
	while (!((VAL_A1 == a->med && b->length == 2) || \
				(VAL_A0 == a->med && b->length == 2)))
		VAL_A1 >= a->med ? RA : PB;
	if (VAL_A1 == a->med)
	{
		if (VAL_A2 > VAL_A0)
			VAL_B1 > VAL_B0 ? ft_rrss(a, b, i, 1) : ft_rrss(a, b, i, 2);
		else
			VAL_B1 > VAL_B0 ? 0 : SB;
	}
	else if (VAL_A0 == a->med)
	{
		if (VAL_A1 > VAL_A2)
			VAL_B1 > VAL_B0 ? SA : SS;
		else
			VAL_B1 > VAL_B0 ? 0 : SB;
		RRA;
	}
}

/*
** THE IDEA IS QUITE THE SAME AS IN DEAL_FIVE, EXCEPT THAT WE PUSH NOT 2 BUT 3
**		MINIMUS ON STACK B, AND THE KEEP THE INITIAL MEDIAN VALUE OF STACK A
**		EITHER AT TOP OR BOTTOM OF IT. THEN WE FIRST SORT STACK A, THEN STACK B
**		IN DECREASING ORDER WHICH IS DONE IN FT_SORTB_WITH_A_LITTLE_L.
**	FOR EVERY SWAP OR ROTATE, CHECKS IF ONE IS NEEDED ON THE OTHER STACK, TO
**		OPTIMIZE THE NUMBER OF MOVES.
*/

static void		ft_deal_six(t_dllist *a, t_dllist *b, int i)
{
	while (!((VAL_A1 == a->med && b->length == 3) || \
				(VAL_A0 == a->med && b->length == 3)))
	{
		if (VAL_A1 == a->med && b->length == 2)
			VAL_B1 < VAL_B0 ? SS : SA;
		else if (VAL_A1 > VAL_A2)
			VAL_A1 < a->med ? SA : RA;
		else
			VAL_A1 < a->med ? PB : RA;
	}
	if (VAL_A1 == a->med)
	{
		if (VAL_A2 > VAL_A0)
			VAL_B1 < VAL_B2 ? ft_rrss(a, b, i, 2) : ft_rrss(a, b, i, 1);
	}
	else
	{
		if (VAL_A1 > VAL_A2)
			(VAL_B1 < VAL_B2) ? SS : SA;
		(VAL_B1 < VAL_B0) ? RRR : RRA;
	}
	ft_sortb_with_a_little_l(a, b, i);
}

/*
**	IF 5 ELEMS : GOEST INTO DEAL_FIVE.
**	IF 6 ELEMS : GOES INTO FT_DEAL_SIX
**	IF 4 ELEMS : PUSH THE SMALLEST 2 ELEMENTS ON STACK B. RA ON THE TWO BIGGEST.
**		THEN SWAP IF NEEDED SO THAT STACK A IS SORTED IN ASCENDING ORDER, AND
**		STACK B IN DESCENDING ORDER. THEN PUSH BACK THE TWO MINIMUMS ON STACK A.
*/

void			ft_sort_medium(t_dllist *a, t_dllist *b, int i)
{
	if (a->length == 5)
		ft_deal_five(a, b, i);
	else if (a->length == 6)
	{
		ft_deal_six(a, b, i);
		PA;
		VAL_B1 < VAL_B0 ? SB : 0;
	}
	else
	{
		while (b->length != 2)
			VAL_A1 >= a->med ? RA : PB;
		if (VAL_B1 < VAL_B0)
			VAL_A1 > VAL_A0 ? SS : SB;
		else
			VAL_A1 > VAL_A0 ? SA : 0;
	}
	PA;
	PA;
}
