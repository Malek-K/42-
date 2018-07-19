/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_path.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/20 15:37:07 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/26 19:25:07 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_initiate(t_info *data, t_path *path)
{
	size_t		i;

	i = data->nb_room;
	while (i)
		data->room[i--]->dist = -1;
	data->room[0]->dist = 0;
	path->room = data->room[0];
}

static int		add_nodes(t_path **path, t_room *room, t_link *links, int nb)
{
	t_path		*new;
	t_path		*begin;

	begin = (*path);
	while (begin->next)
		begin = begin->next;
	while (nb != 0)
	{
		if (links->room->color == 0)
		{
			if (!(new = (t_path*)ft_memalloc(sizeof(t_path))))
				return (-1);
			new->room = links->room;
			new->room->door = room;
			new->room->dist = room->dist + 1;
			links->room->color = 2;
			begin->next = new;
			begin = begin->next;
		}
		links = links->next;
		nb--;
	}
	room->color = 1;
	return (0);
}

static void		ft_do_path(t_path *path)
{
	t_path		*start;

	start = path;
	while (start)
	{
		path = start;
		add_nodes(&start, start->room, start->room->links, start->room->link);
		start = start->next;
		ft_memdel((void**)&path);
	}
}

static void		ft_do_sol(t_room *end)
{
	while (end->door)
	{
		end->door->exit = end;
		end = end->door;
	}
}

int				ft_create_path(t_info *data, t_check *list)
{
	t_path		*path;

	if (!(path = (t_path*)ft_memalloc(sizeof(t_path))))
		return (-1);
	ft_initiate(data, path);
	ft_do_path(path);
	if (data->room[1]->color)
	{
		ft_do_sol(data->room[1]);
		print_list(list);
		ft_print_sol(data->room[1], data);
	}
	else
		ft_putendl("ERROR : No Path Between Start and End");
	return (0);
}
