/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:32:11 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 16:01:02 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_pa(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	if (b->length > 0)
	{
		tmp = b->next;
		b->next = tmp->next;
		b->next->prev = b;
		b->length--;
		tmp->next = a->next;
		tmp->prev = a;
		a->next->prev = tmp;
		a->next = tmp;
		a->length++;
	}
	i == 2 ? ft_printf("{blu}pa{eoc}\n") : 0;
	i == 1 ? ft_printf("pa\n") : 0;
	a->moves++;
}
