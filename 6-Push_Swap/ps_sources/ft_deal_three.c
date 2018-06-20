/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_three.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 20:33:07 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 16:15:59 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	FT_AUX DEALS WITH THE CASE 2  & 3:
**	FIRST IF : 3RD VALUE IS MAX (2-1-3), THE CASE (1-2-3) IS SORTED AND WOULD
**		ALREADY HAD BEEN PUT AT THE BOTTOM OF STACK A.
**	FINAL ELSE - 2ND VALUE IS MAX (1-3-2 || 2-3-1)
*/

static void		ft_aux(t_dllist *a, t_dllist *b, int i)
{
	if (VAL_A1 > VAL_A2)
	{
		SA;
		RA;
		RA;
		RA;
	}
	else
	{
		PB;
		SA;
		RA;
		PA;
		RA;
		RA;
	}
}

/*
**	FT_DEAL_THREE TAKES CARE OF THE DIFFERENT CASES WITH 3 ELEMENTS.
**	THERE ARE 3 SCENARIOS, FOR A TOTAL OF 6 CASES:
**	1 - 1ST VALUE IS MAX (3-2-1 || 3-1-2)
**			PUT MAX ON STACK B, SWAP A IF NEEDDED IN ORDER TO HAVE MIN ON TOP
**				OF STACK A. (A = 1-2 && B = 3)
**			THEN RA TWICE FOR THE 2 MINIMUM VALUES ON TOP OF STACK A, THEN
**				PUSH MAX BACK ON STACK A AND RA TO PUT IT AT THE BOTTOM.
**	2 - 2ND VALUE IS MAX, DEALT WITH IN FT_AUX (1-3-2 || 2-3-1)
**	3 - 3RD VALUE IS MAX, DEALT WITH IN FT_AUX (2-1-3)
*/

void			ft_deal_three(t_dllist *a, t_dllist *b, int i)
{
	if (VAL_A1 > VAL_A2 && VAL_A1 > VAL_A3)
	{
		PB;
		VAL_A1 > VAL_A2 ? SA : 0;
		RA;
		RA;
		PA;
		RA;
	}
	else
		ft_aux(a, b, i);
	a->sortednb += 3;
}
