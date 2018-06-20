/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_real_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/18 15:09:15 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 19:23:17 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	THE DIFFERENT STEPS IN FT_FILTER :
**	SAME IDEA AS IN MAXI_SORTB
*/

static void		ft_filter(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*piv;

	piv = a->prev;
	while (a->next != piv)
	{
		if (VAL_A1 < a->med)
			PB;
		else if (VAL_A1 == a->med)
		{
			PB;
			VAL_A1 < a->med ? RB : RR;
		}
		else
			RA;
		if (b->length > a->length)
			break ;
	}
	if (VAL_A1 < a->med)
		PB;
	if (VAL_A1 != a->med)
	{
		VAL_A0 < VAL_A1 ? RRR : RRB;
		PA;
	}
}

/*
**	THE DIFFERENT STEPS IN FT_FINDMED :
**	THE IDEA IS TO LOOK AT ALL ELEMENTS IN THE LIST, UNTILL WE FIND ONE THAT
**	HAVE HALF BIFFER AND HALT LOWER. IF THE NUMBER OF ELEM ON THE STACK IS EVEN
**	WE TAKE THE ELEMT BIGGER TO THE MEDIAN VALUE
**	1- DEFINE A POINTER TMP ON FIRST ELEMENT OF B
**	2- DEFINE A 2ND POINTER TMP2 ON THE NEXT ELEMENT
**	3- LOOP : AS LONG AS TMP2->NEXT IS NOT TMP, MEANING WE'VE DONE ALL VALUES
**		A - IF BIGGER THAN TMP VALUE	==>	INCREMENT COUNTER
**		B - ELSE						==>	DECREMENT COUNTER
**	4- IF COUNTER == 0 or -1, WE HAVE FOUND THE MEDIAN, BREAK THE LOOP
**	ELSE PUT TMP ON THE NEXT ELEMENT AND START THE LOOP AGAIN, UNTILL WE FIND
**	THE MEDIAN VALUE
*/

static int		ft_findpmed(t_dllist *b)
{
	t_dllist	*tmp;
	t_dllist	*tmp2;
	int			med;

	tmp = b->next;
	tmp2 = tmp->next;
	med = 0;
	if (b->next != b)
	{
		while (!((med == -1 || med == 0) && tmp2->val == tmp->val))
		{
			med = 0;
			tmp2 = tmp->next;
			tmp2 == b ? tmp2 = tmp2->next : 0;
			while (tmp2->val != tmp->val)
			{
				tmp2->val > tmp->val ? med++ : med--;
				tmp2 = tmp2->next;
				tmp2 == b ? tmp2 = tmp2->next : 0;
			}
			!(med == -1 || med == 0) ? tmp = tmp->next : 0;
		}
	}
	return (tmp->val);
}

/*
**	THE DIFFERENT STEPS IN FT_MAXI_SORTB :
**	THE IDEA IS TO HAVE ELEMETS LOWER THAN MED IN STACK B, BIGGER ON STACK A
**	AND FINALLY, THE MEDIAN ON TOP OF THE PACKET ON STACK A
**	1- DEFINE THE LAST ELEMENT AS THE PIVOT AND DETERMINE THE MEDIAN VALUE IN B
**	2- AS LONG AS WE RE NOT ON THE PIVOT, OR B->LENGTH /= 2 :
**		A - IF BIGGER THAN MEDIAN	==>	PUSH ON STACK A
**		B - ELSE IF LOWER THAN		==>	PUT BELOW STACK B
**		C - ELSE IF MEDIAN			==> PUT ON, THEN BELOW STACK A,
**													EXCEPT IF LAST
**	3- IF THE MEDIAN WAS NOT THE LAST ELEMENT, PUT IT BACK ON TOP OF THE PACKET
*/

static void		ft_maxi_sortb(t_dllist *a, t_dllist *b, int i, intmax_t *nb)
{
	t_dllist	*piv;

	piv = b->prev;
	b->med = ft_findpmed(b);
	while (b->next != piv)
	{
		if (VAL_B1 >= b->med)
		{
			PA;
			if (VAL_A1 == b->med)
				VAL_B1 < b->med ? RR : RA;
			(*nb)++;
		}
		else
			RB;
		if (*nb >= b->length)
			break ;
	}
	if (piv->val >= b->med)
	{
		PA;
		(*nb)++;
	}
	VAL_A1 == b->med ? 0 : RRA;
}

/*
**	THE DIFFERENT STEPS IN FT_SORT_B :
**	1- FINAL RETURN CONDITION : RETURN WHEN THE NUMBERS OF STACK B WERE SORTED
**	2- IF THE PACKET IS SMALLER OR EQUAL TO 33: DO INSERTION SORT
**		AS ALL THE ELEMENTS WILL BE SORTED, RETURN AFTERWARDS.
**	3- IF THE PACK IS BIGGER THAN 33 : DO MAXI_SORT
**		THEN RECURSIVELY CALL FT_SORT_B UNTILL THERE ARE LESS THAN 33 ELEMENTS
**		ON STACK B.
*/

static void		ft_sort_b(t_dllist *a, t_dllist *b, int i, intmax_t nb)
{
	intmax_t	tmp;

	if (a->sortednb == a->rest || a->sortednb == a->tot)
		return ;
	tmp = nb;
	if (b->length <= 33)
	{
		ft_ins_sort(a, b, i);
		return ;
	}
	else if (b->length > 33)
	{
		nb = 0;
		ft_maxi_sortb(a, b, i, &nb);
		ft_sort_b(a, b, i, nb);
	}
	if (ft_repush(a, b, i, &nb) != 0)
		ft_sort_b(a, b, i, nb);
	return ;
}

/*
**	THE DIFFERENT STEPS REAL_SORT :
**	1- INITIALISATION OF THE IMPORTANT VALUES IN STACK A
**	2- DIVIDE STACK A IN 2 HALVES USING THE MEDIAN VALUE
**	3- SORTING B WITH A MIX OF QUICKSORT AND INSERTION SORT
**	4- PUSHING THE OTHER HALF ON B AND SORTING AGAIN
*/

void			ft_real_sort(t_dllist *a, t_dllist *b, int i)
{
	a->sortednb = 0;
	a->push = 0;
	a->tot = a->length;
	ft_filter(a, b, i);
	a->rest = a->length;
	b->length >= 33 ? ft_sort_b(a, b, i, 0) : ft_ins_sort(a, b, i);
	a->rest = (a->tot - a->sortednb);
	a->push = 1;
	ft_repush(a, b, i, &a->rest);
	if (a->print == 1 && a->tot > 12)
	{
		ft_printf("\n**** | LISTS AT MIDTIME REPUSH | ****\n");
		ft_printlists(a, b);
	}
	if (b->length > 35)
		ft_sort_b(a, b, i, 0);
	else if (b->length > 0 && b->length <= 35)
		ft_ins_sort(a, b, i);
}
