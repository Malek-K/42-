/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rra.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:10:57 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/10 15:47:13 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void			ft_rra(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)b;
	if (a->length > 1)
	{
		tmp = a->prev;
		a->prev = tmp->prev;
		a->prev->next = a;
		tmp->next = a->next;
		tmp->prev = a;
		a->next->prev = tmp;
		a->next = tmp;
	}
	i == 2 ? ft_printf("{gre}rra{eoc}\n") : 0;
	i == 1 ? ft_printf("rra\n") : 0;
	a->moves++;
}
