/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ra.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 15:49:27 by mkamel            #+#    #+#             */
/*   Updated: 2018/04/28 20:00:49 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			ft_ra(t_dllist *a, t_dllist *b, int i)
{
	t_dllist	*tmp;

	(void)b;
	if (a->length > 1)
	{
		tmp = a->next;
		a->next = tmp->next;
		a->next->prev = a;
		tmp->next = a;
		tmp->prev = a->prev;
		a->prev->next = tmp;
		a->prev = tmp;
	}
	i == 2 ? ft_printf("{red}ra{eoc}\n") : 0;
	i == 1 ? ft_printf("ra\n") : 0;
}
