/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_repush.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 14:39:31 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/07 16:13:15 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	DEALS WITH PACKETS ON A THAT HAVE TO BE REPUSH TO BE SORTED, KNOWING THAT
**	THE SMALLEST ELEMENT IS ALWAYS ON TOP OF THE PACKET.
**	IF THE PACKET IS EQUAL OR SMALLER THAN THREE, SORTING IS EASY AND
**		NEED NO REPUSH.
**	ELSE GOES INTO DEAL_BIG_X AND CHECK IF FULL REPUSH IS NEEDED OR NOT,
**	IF SIZE OF THE PACKET IS LESS THAN 6 AND SORT THEM IN THAT CASE.
*/

int		ft_repush(t_dllist *a, t_dllist *b, int i, intmax_t *nb)
{
	if ((a->sortednb == a->rest && a->push == 0) || a->sortednb >= a->tot)
		return (0);
	if (*nb > 3)
	{
		RA;
		a->sortednb += 1;
		(*nb)--;
		return (ft_deal_bigx(a, b, i, *nb) == 0) ? 0 : 1;
	}
	if (*nb > 0 && *nb <= 2)
	{
		(*nb == 2 && VAL_A1 >= VAL_A2) ? SA : 0;
		*nb == 2 ? RA : 0;
		RA;
		a->sortednb += (*nb == 2) ? 2 : 1;
	}
	else if (*nb == 3)
	{
		RA;
		VAL_A1 > VAL_A2 ? SA : 0;
		RA;
		RA;
		a->sortednb += 3;
	}
	return (0);
}
