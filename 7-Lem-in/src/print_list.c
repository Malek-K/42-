/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_list.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/04 18:00:41 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/22 19:06:31 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		print_list(t_check *list)
{
	if (!list->line)
		return ;
	while (list)
	{
		ft_printf("%s\n", list->line);
		list = list->next;
	}
}
