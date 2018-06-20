/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_three_inb.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/24 15:22:59 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/07 16:10:30 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void		ft_sr(t_dllist *a, t_dllist *b, int i)
{
	SB;
	RB;
}

/*
**	AFTER REPUSH, SAME SORTING AS SORT_LITTLE, BUT IN DECREASING ORDER.
**	THE BIGGEST IS THE FIRST ELEMENT, SO THAT WHEN PUSHED BACK, THE SMALLEST
**		IS ON TOP OF STACK A.
*/

void		ft_sort_three_inb(t_dllist *a, t_dllist *b, int i)
{
	if (VAL_B1 > VAL_B2)
	{
		if (!(VAL_B2 > VAL_B0))
			VAL_B1 < VAL_B0 ? RRB : ft_sr(a, b, i);
	}
	else
	{
		if (!(VAL_B1 < VAL_B0 && VAL_B2 > VAL_B0))
		{
			SB;
			if (VAL_B2 < VAL_B0)
				VAL_B1 < VAL_B0 ? RRB : 0;
		}
		else
			RB;
	}
}
