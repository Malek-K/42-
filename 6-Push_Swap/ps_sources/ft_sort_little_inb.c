/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_little_inb.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/25 15:40:39 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/05 18:13:09 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void		ft_srb(t_dllist *a, t_dllist *b, int i)
{
	SB;
	RB;
}

/*
**	SAME AS SORT LITTLE, BUT IN B...
*/

void			ft_sort_little_inb(t_dllist *a, t_dllist *b, int i)
{
	if (VAL_B1 < VAL_B2)
	{
		if (!(VAL_B2 < VAL_B0))
			VAL_B1 > VAL_B0 ? RRB : ft_srb(a, b, i);
	}
	else
	{
		if (!(VAL_B1 > VAL_B0 && VAL_B2 < VAL_B0))
		{
			SB;
			if (VAL_B2 > VAL_B0)
				VAL_B1 > VAL_B0 ? RRB : 0;
		}
		else
			RB;
	}
}
