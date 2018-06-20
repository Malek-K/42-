/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sel_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/07 16:15:56 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 17:53:35 by mkamel           ###   ########.fr       */
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
**		WE ARE FOCUSIING ON, THE MAXIMUM IS THE ONE HAVING NO VALUE SUPERIOR TO
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

/*
**	DEALS A PACKET OF MAXIMUM FIVE ELEMENTS.
**	PUSH THREE ELEMENTS ON B, SORT THEM AND THOSE THAT STOOD ON STACK A.
**	THEN COMPARE THE SMALLEST (ON TOP OF EACH STACKS) AND PUT THE SMALLEST
**		IN ORDER AT THE BOTTOM
*/

static void		ft_deal_five(t_dllist *a, t_dllist *b, int i, int x)
{
	a->sortednb += x;
	while (b->length > 3)
		PA;
	ft_sort_little_inb(a, b, i);
	VAL_A1 > VAL_A2 ? SA : 0;
	if (VAL_A1 == a->min && a->sortednb < (a->tot - 3) && x--)
		RA;
	while (b->length != 0)
	{
		if (VAL_B1 < VAL_A1)
		{
			PA;
			RA;
		}
		else if (VAL_B1 > VAL_A1)
		{
			VAL_A1 == a->min && VAL_A2 < VAL_B1 ? PA : 0;
			RA;
		}
		x--;
	}
	while (x-- > 0)
		RA;
}

/*
**	USES THE INSERTION SORT ON A PACKET OF LESS THAN 35 ELEMENTS.
**	STEPS OF THE SORTING : 2 LOOPS
**	1ST LOOP : UNTILL THERE IS LESS THAN 6 ELEMENTS ON STACK B
**		1 - FIND THE POSITION OF THE PRESENT MIN AND MAX IN STACK B
**		2 - PUSH THE ONE REQUIRING THE SMALLEST NUMBER OF MOVES ON STACK A.
**				IF IT'S THE MIN, PUT IT AT THE BOTTOM OF STACK A.
**				IF IT'S THE MAX, PUT IT AT THE TOP OF STACK A.
**	BETWEEN THE LOOPS : FT_DEAL_FIVE SORT THE FIVE LAST NUMBERS ON STACK B,
**		AND PUT THEM AT THE BOTTOM OF STACK A.
**	2ND LOOP : PUT ALL THE PREVIOUS SORTED MAXIMUMS FROM THE TOP TO THE BOTTOM
**		OF STACK A.
*/

void			ft_ins_sort(t_dllist *a, t_dllist *b, int i)
{
	a->to_push = 0;
	while (b->length > 5)
	{
		B_MNH = 0;
		B_MXH = 0;
		b->min = ft_find_min(b);
		b->max = ft_find_max(b);
		ft_decide(a, b, i);
	}
	b->length != 0 ? ft_deal_five(a, b, i, b->length) : 0;
	while (a->to_push != 0)
	{
		RA;
		a->sortednb++;
		a->to_push--;
	}
}
