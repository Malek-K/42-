/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_sol.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/21 16:10:20 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/25 17:04:05 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			ft_print_sol(t_room *end, t_info *data)
{
	t_room		*start;

	start = end;
	data->room[0]->used = data->ant;
	ft_printf("\n");
	while (end->used != data->ant)
	{
		start = end;
		while (start != data->room[0])
		{
			if (start->door->used && start->used != start->door->used)
			{
				start->used++;
				if (start != end && start->exit->used)
					ft_printf(" ");
				ft_printf("L%d-%s", start->used, start->name);
			}
			start = start->door;
		}
		ft_printf("\n");
	}
}
