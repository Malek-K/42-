/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deal_bigx.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/26 15:03:17 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/07 16:14:21 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static int		ft_sortedpack(t_dllist *a, intmax_t x)
{
	t_dllist	*tmp;

	tmp = a->next;
	x -= 1;
	while (x)
	{
		if (tmp->val > tmp->next->val)
			return (-1);
		tmp = tmp->next;
		x--;
	}
	return (0);
}

static int		ft_first_ismin(t_dllist *a, intmax_t x)
{
	t_dllist	*tmp;
	int			k;

	tmp = a->next->next;
	x -= 1;
	k = x;
	while (x)
	{
		if (tmp->val < VAL_A1)
			break ;
		else
			tmp->next->val != a->min ? tmp = tmp->next : 0;
		x--;
	}
	if (tmp->val > VAL_A1 && x == 0)
		return (1);
	return (0);
}

/*
**	DEALS A PACKET OF FOUR OR FIVE ELEMENTS.
**	PUSH THREE ELEMENTS ON B, SORT THEM AND THE TWO THAT STOOD ON STACK A.
**	THEN COMPARE THE SMALLEST (ON TOP OF EACH STACKS) AND PUT THE SMALLEST
**		IN ORDER AT THE BOTTOM
*/

static void		ft_deal_ff(t_dllist *a, t_dllist *b, int i, intmax_t x)
{
	a->sortednb += (x == 4) ? 4 : 5;
	while (b->length != 3)
		PB;
	ft_sort_little_inb(a, b, i);
	(x == 5 && VAL_A1 > VAL_A2) ? SA : 0;
	while (b->length != 0)
	{
		if (VAL_B1 < VAL_A1)
		{
			PA;
			RA;
		}
		else if (VAL_B1 > VAL_A1)
		{
			VAL_A1 == a->min ? PA : 0;
			RA;
		}
		x--;
	}
	while (x-- != 0)
		RA;
}

static void		ft_deal_one_two(t_dllist *a, t_dllist *b, int i, intmax_t x)
{
	(x == 2 && VAL_A1 > VAL_A2) ? SA : 0;
	RA;
	x == 2 ? RA : 0;
	a->sortednb += (x == 2) ? 2 : 1;
}

/*
**	FIRST CHECK IF THE PACKET IS SORTED. IF YES, SIMPLY RA ALL THE PACKET.
**	IF NOT, IS THE FIRST ELEM THE MIN. IF YES THEN ROTATE UNTIL IT'S NOT.
**	AFTER THAT, DEPENDING OF THE SIZE : EASY SORT IF THE PACKET IS INFERIOR TO
**		5 NUMBERS;
**	ELSE REPUSH ALL ON STACK B TO GO THROUGH FT_SORT_B AGAIN.
*/

int				ft_deal_bigx(t_dllist *a, t_dllist *b, int i, intmax_t x)
{
	if (ft_sortedpack(a, x) != -1)
		while (x-- && a->sortednb++)
			RA;
	else
	{
		while (ft_first_ismin(a, x) == 1 && a->sortednb++ && x--)
			RA;
		if (x > 5)
		{
			while (x--)
				PB;
			return (1);
		}
		else if (x == 4 || x == 5)
			ft_deal_ff(a, b, i, x);
		else if (x == 3)
			ft_deal_three(a, b, i);
		else if (x == 1 || x == 2)
			ft_deal_one_two(a, b, i, x);
	}
	return (0);
}
