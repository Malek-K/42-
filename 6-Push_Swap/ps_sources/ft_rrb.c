/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:10:57 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 15:47:18 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_rrb(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)a;
	if (b->length > 1)
	{
		tmp = b->prev;
		b->prev = tmp->prev;
		b->prev->next = b;
		tmp->next = b->next;
		tmp->prev = b;
		b->next->prev = tmp;
		b->next = tmp;
	}
	i == 2 ? ft_printf("{gre} {bal}rrb{eoc}\n") : 0;
	i == 1 ? ft_printf("rrb\n") : 0;
	a->moves++;
}
