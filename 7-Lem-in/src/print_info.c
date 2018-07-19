/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 15:15:11 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/22 20:23:07 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define DR datas->room

static void		print_room(t_room *room)
{
	ft_printf("\tx: 		[%d]\n", room->x);
	ft_printf("\ty: 		[%d]\n", room->y);
	ft_printf("\tnum:	 	[%d]\n", room->num);
	ft_printf("\tname:		[%s]\n", room->name);
}

void			print_info(t_info *datas)
{
	int			i;

	i = 0;
	ft_printf("used_room =  %zu\n\n", datas->used_room);
	while (i < (int)datas->used_room)
	{
		ft_printf("s_room num %d : name =  %s\nx = %d\ny = %d\nlinks = %d\n",
				DR[i]->num, DR[i]->name, DR[i]->x, DR[i]->y, DR[i]->link);
		while (DR[i]->links)
		{
			ft_printf("s_room[%d] -> link to [%d]\n", DR[i]->num,
					DR[i]->links->num);
			print_room(DR[i]->links->room);
			DR[i]->links = DR[i]->links->next;
		}
		ft_putstr("\n\n");
		i++;
	}
}
