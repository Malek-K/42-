/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_link.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/12 17:31:50 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/27 19:52:01 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		check_new_link(int num, t_link *link)
{
	t_link	*tmp;

	tmp = link;
	while (tmp)
	{
		if (num == tmp->num)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static void		add_new(int num, t_link *link, t_room *room)
{
	t_link		*begin;
	t_link		*new;

	begin = link;
	if (!(new = (t_link*)ft_memalloc(sizeof(t_link))))
		return ;
	while (begin->next)
		begin = begin->next;
	new->num = num;
	new->room = room;
	new->next = NULL;
	begin->next = new;
}

static void		add_link(char *name_a, char *name_b, t_info *data, int i)
{
	int			j;

	j = -1;
	while (data->room[++i])
		if (!ft_strcmp(name_a, data->room[i]->name))
			break ;
	while (data->room[++j])
		if (!ft_strcmp(name_b, data->room[j]->name))
			break ;
	if (!(data->room[i]->links))
	{
		if (!(data->room[i]->links = (t_link*)ft_memalloc(sizeof(t_link))))
			return ;
		data->room[i]->links->num = data->room[j]->num;
		data->room[i]->links->room = data->room[j];
		data->room[i]->links->next = NULL;
		data->room[i]->link += 1;
	}
	else if (check_new_link(data->room[j]->num, data->room[i]->links))
	{
		data->room[i]->link += 1;
		add_new(data->room[j]->num, data->room[i]->links, data->room[j]);
	}
}

void			fill_link(t_check *list, t_info *data, size_t i)
{
	t_check		*tmp;
	char		**arg;

	tmp = list;
	i == 0 ? i = 2147483647 : 0;
	while (tmp && tmp->line && i--)
	{
		while (ft_strchr(tmp->line, '#'))
		{
			if (!tmp->next)
				return ;
			tmp = tmp->next;
		}
		arg = ft_strsplit(tmp->line, '-');
		if (arg[0] && arg[1] && !arg[2])
		{
			add_link(arg[0], arg[1], data, -1);
			add_link(arg[1], arg[0], data, -1);
		}
		delete_arg(arg);
		tmp = tmp->next;
	}
}
