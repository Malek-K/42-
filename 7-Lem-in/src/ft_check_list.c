/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_list.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 17:04:24 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/29 13:53:44 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		ft_check_nb(t_check **list, t_info *data)
{
	int			i;

	i = 0;
	if (!(*list)->line || !(*list)->line[0])
		return (0);
	while ((*list)->line[0] == '#' && ft_strcmp((*list)->line, "##start") && \
			ft_strcmp((*list)->line, "##end"))
		(*list) = (*list)->next;
	if (!ft_strchr("-", (*list)->line[i]))
		i++;
	while (ft_isdigit((*list)->line[i]))
		i++;
	if ((*list)->line[i] || i > 11 ||
			ft_atoll((const char*)(*list)->line) > 2147483647 ||
			ft_atoll((const char*)(*list)->line) <= 0)
	{
		ft_putendl_fd("ERROR : Incorrect input for number of ants.", 2);
		return (-1);
	}
	data->ant = (int)ft_atoll((const char*)(*list)->line);
	if ((*list)->next)
		(*list) = (*list)->next;
	return (0);
}

static int		ft_check(t_check **test, int j, char **arg)
{
	arg = ft_strsplit((*test)->line, ' ');
	if (!(*arg))
	{
		delete_arg(arg);
		return (-1);
	}
	if (j == 0 && *arg && ft_strchr(arg[0], '-'))
	{
		delete_arg(arg);
		return (0);
	}
	if (j != 2 || !my_isdigit(arg[1]) || !my_isdigit(arg[2]) ||
			ft_strchr(arg[0], '-') || *arg[0] == 'L' || *arg[0] == '#')
	{
		delete_arg(arg);
		return (-1);
	}
	delete_arg(arg);
	return (1);
}

static int		ft_check_rooms(t_check **test, t_info **data, char **arg, int i)
{
	int			j;

	while ((*test))
	{
		i = 0;
		j = 0;
		while (!ft_strncmp((*test)->line, "#", 1))
		{
			if (!(*test)->next)
				return (0);
			(*test) = (*test)->next;
		}
		while ((*test)->line[i])
			if ((*test)->line[i++] == ' ')
				j++;
		if (!ft_check(test, j, arg))
			return (0);
		else if (ft_check(test, j, arg) == -1)
			return (-1);
		(*data)->nb_room += 1;
		(*test) = (*test)->next;
	}
	return (0);
}

int				ft_check_list(t_check *list, t_info *data, size_t i, size_t nb)
{
	char		**arg;
	t_check		*test;

	arg = NULL;
	test = list;
	if (ft_check_nb(&test, data) || ft_check_start_n_end(test, data))
		return (-1);
	if (ft_check_rooms(&test, &data, arg, 0))
		return (2);
	nb = data->nb_room;
	if (!(data->room = (t_room**)ft_memalloc(sizeof(t_room*) * (nb + 1))))
		return (-1);
	while (i <= data->nb_room)
		if (!(data->room[i++] = (t_room*)ft_memalloc(sizeof(t_room))))
			return (-1);
	if (fill_info(list, data))
		return (4);
	if (nb == 1 || (data->room[0]->x == data->room[1]->x &&
				data->room[0]->y == data->room[1]->y))
		return (3);
	i = ft_check_pipes(test, data, 0, 0);
	fill_link(test, data, i);
	return (0);
}
