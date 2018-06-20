/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 17:00:51 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 16:01:10 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_pb(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	if (a->length > 0)
	{
		tmp = a->next;
		a->next = tmp->next;
		a->next->prev = a;
		a->length--;
		tmp->next = b->next;
		tmp->prev = b;
		b->next->prev = tmp;
		b->next = tmp;
		b->length++;
	}
	i == 2 ? ft_printf("{blu} {bal}pb{eoc}\n") : 0;
	i == 1 ? ft_printf("pb\n") : 0;
	a->moves++;
}
