/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_decide.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:33:23 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 20:17:17 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#define B_MNH b->min_hits
#define B_MXH b->max_hits

/*
**	LOOKS FOR MINIMUM PRESENT VALUE IN LIST B.
**	CREATES A POINTER ON THE FIRST ELEMENT ON B, AND ANOTHER ONE WHICH WILL GO
**		THROUGH ALL LIST B. USING A COUNTER FOR EVERY VALUE INFERIOR TO THE ONE
**		WE ARE FOCUSIING ON, THE MINIMUM IS THE ONE HAVING NO VALUE INFERIOR TO
**		IT.
*/

static int		ft_find_min(t_dllist *b)
{
	t_dllist	*tmp;
	t_dllist	*tmp2;
	int			min;

	tmp = b->next;
	tmp2 = tmp->next;
	min = 0;
	if (b->next != b)
	{
		while (!(min == 0 && tmp2->val == tmp->val))
		{
			min = 0;
			tmp2 = tmp->next;
			tmp2 == b ? tmp2 = tmp2->next : 0;
			while (tmp2->val != tmp->val)
			{
				tmp2->val < tmp->val ? min++ : 0;
				tmp2 = tmp2->next;
				tmp2 == b ? tmp2 = tmp2->next : 0;
			}
			!(min == 0) ? tmp = tmp->next : 0;
			B_MNH++;
		}
	}
	return (tmp->val);
}

/*
**	LOOKS FOR MAXIMUM PRESENT VALUE IN LIST B.
**	CREATES A POINTER ON THE FIRST ELEMENT ON B, AND ANOTHER ONE WHICH WILL GO
**		THROUGH ALL LIST B. USING A COUNTER FOR EVERY VALUE SUPERIOR TO THE ONE
**		WE ARE FOCUSING ON, THE MAXIMUM IS THE ONE HAVING NO VALUE SUPERIOR TO
**		IT.
*/

static int		ft_find_max(t_dllist *b)
{
	t_dllist	*tmp;
	t_dllist	*tmp2;
	int			max;

	tmp = b->next;
	tmp2 = tmp->next;
	max = 0;
	if (b->next != b)
	{
		while (!(max == 0 && tmp2->val == tmp->val))
		{
			max = 0;
			tmp2 = tmp->next;
			tmp2 == b ? tmp2 = tmp2->next : 0;
			while (tmp2->val != tmp->val)
			{
				tmp2->val > tmp->val ? max++ : 0;
				tmp2 = tmp2->next;
				tmp2 == b ? tmp2 = tmp2->next : 0;
			}
			!(max == 0) ? tmp = tmp->next : 0;
			B_MXH++;
		}
	}
	return (tmp->val);
}

static void		ft_min_ismin(t_dllist *a, t_dllist *b, int i)
{
	if (B_MNH < (b->length / 2 + 1))
		while (VAL_B1 != b->min)
			RB;
	else
		while (VAL_B1 != b->min)
			RRB;
	PA;
	B_MNH = 0;
	B_MXH = 0;
	b->min = ft_find_min(b);
	b->max = ft_find_max(b);
	(B_MNH < (b->length / 2 + 1) || B_MXH < (b->length / 2 + 1)) ? RR : RA;
	a->sortednb++;
}

/*
**	FT_DECIDE CHOSSE WHICH OF THE PRESENT MAX OR THE PRESENT MIN IS THE CLOSEST
**		TO THE TOP OF THE LIST, AND DO THE MOVES TO BRING IT THERE.
**	IF THEY ARE AT AN EQUAL NUMBER OF MOVES, IT PREFERS THE MINIMUM.
**	THE FUNCTION WORKS IN 2 STEPS :
**	1 - FIND THE MIN AND THE MAX AND DETERMINE THE NUMBER OF MOVES THEY NEED.
**	2 - BRINGS THE CLOSEST TO THE TOP.
*/

void			ft_decide(t_dllist *a, t_dllist *b, int i)
{
	int		minh;
	int		maxh;

	maxh = (B_MXH > b->length / 2) ? b->length - B_MXH + 1 : B_MXH;
	minh = (B_MNH > b->length / 2) ? b->length - B_MNH + 1 : B_MNH;
	if (minh <= maxh)
		ft_min_ismin(a, b, i);
	else
	{
		if (B_MXH < (b->length / 2 + 1))
			while (VAL_B1 != b->max)
				RB;
		else
			while (VAL_B1 != b->max)
				RRB;
		PA;
		a->to_push++;
	}
}
