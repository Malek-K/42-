/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sa.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 13:56:18 by mkamel            #+#    #+#             */
/*   Updated: 2018/04/28 20:04:11 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			ft_sa(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)b;
	if (a->length > 1)
	{
		tmp = a->next;
		a->next = tmp->next;
		a->next->prev = a;
		tmp->next = a->next->next;
		tmp->prev = a->next;
		a->next->next->prev = tmp;
		a->next->next = tmp;
	}
	i == 2 ? ft_printf("{yel}sa{eoc}\n") : 0;
	i == 1 ? ft_printf("sa\n") : 0;
}
