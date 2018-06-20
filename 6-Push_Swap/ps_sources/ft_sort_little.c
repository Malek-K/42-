/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_little.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 14:41:50 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 20:08:42 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_sra(t_dllist *a, t_dllist *b, int i)
{
	SA;
	RA;
}

/*
**	SORT TWO OR  THREE NUMBERS ON STACK A, KNOWING THE LIST IS NOT SORTED
**	TWO MAIN CASES TO DEAL :
**	1 - THE FIRST VALUE IS INFERIOR TO THE SECOND (1-3-2 || 2-3-1)
**			IF THE SECOND IS SUPERIOR TO THE THIRD (1-3-2) :
**				SA => (3-1-2) + RA => (1-2-3)
**			IF THE 3RD IS INFERIOR TO THE FIRST (2-3-1) : RRA (1-2-3)
**	2 - THE 1ST VALUE IS SUPERIOR TO THE 2ND (3-1-2 || 3-2-1 || 2-1-3)
**			FINAL ELSE :  THE 1ST IS SUPERIOR TO THE 3RD (3-1-2) : RA (1-2-3)
**			IF NOT, TWO SUBCASES : (3-2-1 || 2-1-3)
**				THEN SWAP A : (2-3-1 || 1-2-3), 2ND SUBCASE IS SORTED
**				IF SUBCASE 1 (2-3-1) : RRA ->(1-2-3)
*/

void			ft_sort_little(t_dllist *a, t_dllist *b, int i)
{
	if (a->length == 2)
	{
		if (VAL_A0 < VAL_A1)
			SA;
	}
	if (a->length == 3)
	{
		if (VAL_A1 < VAL_A2)
		{
			if (!(VAL_A2 < VAL_A0))
				VAL_A1 > VAL_A0 ? RRA : ft_sra(a, b, i);
		}
		else
		{
			if (!(VAL_A1 > VAL_A0 && \
						VAL_A2 < VAL_A0))
			{
				SA;
				if (VAL_A2 > VAL_A0)
					VAL_A1 > VAL_A0 ? RRA : 0;
			}
			else
				RA;
		}
	}
}
