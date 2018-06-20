/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rb.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:57:08 by mkamel            #+#    #+#             */
/*   Updated: 2018/04/28 20:01:20 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			ft_rb(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)a;
	if (b->length > 1)
	{
		tmp = b->next;
		b->next = tmp->next;
		b->next->prev = b;
		tmp->next = b;
		tmp->prev = b->prev;
		b->prev->next = tmp;
		b->prev = tmp;
	}
	i == 2 ? ft_printf("{red} {bal}rb{eoc}\n") : 0;
	i == 1 ? ft_printf("rb\n") : 0;
}
