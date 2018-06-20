/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rrr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/29 16:26:01 by mkamel            #+#    #+#             */
/*   Updated: 2018/04/28 20:02:42 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void			ft_rrr(t_dllist *a, t_dllist *b, int i)
{
	ft_rra(a, b, 0);
	ft_rrb(a, b, 0);
	i == 2 ? ft_printf("{gre} {und}rrr{eoc}\n") : 0;
	i == 1 ? ft_printf("rrr\n") : 0;
}
