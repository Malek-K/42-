/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:38:19 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 16:01:54 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_sb(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)a;
	if (b->length > 1)
	{
		tmp = b->next;
		b->next = tmp->next;
		b->next->prev = b;
		tmp->next = b->next->next;
		tmp->prev = b->next;
		b->next->next->prev = tmp;
		b->next->next = tmp;
	}
	i == 2 ? ft_printf("{yel} {bal}sb{eoc}\n") : 0;
	i == 1 ? ft_printf("sb\n") : 0;
	a->moves++;
}
