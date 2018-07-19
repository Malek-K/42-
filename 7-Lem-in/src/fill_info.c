/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_info.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/11 15:11:26 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/29 15:03:09 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define DR data->room

static void		ft_end(t_check *list, t_info *data, char **arg, t_check *tmp)
{
	tmp = list;
	while (tmp)
	{
		if (!(ft_strcmp(tmp->line, "##end")))
		{
			while (tmp->line[0] == '#')
				tmp = tmp->next;
			if (tmp)
			{
				arg = ft_strsplit(tmp->line, ' ');
				if (arg[0] && arg[1] && arg[2] && !arg[3])
				{
					if (DR[1]->name)
						ft_memdel((void**)&DR[1]->name);
					DR[1]->name = ft_strdup(arg[0]);
					DR[1]->x = (int)my_atoll(arg[1], list, data, 0);
					DR[1]->y = (int)my_atoll(arg[2], list, data, 0);
					DR[1]->num = 1;
				}
				delete_arg(arg);
				data->used_room == 1 ? data->used_room = 2 : 0;
			}
		}
		tmp = tmp->next;
	}
}

static void		ft_start(t_check *list, t_info *data, char **arg, t_check *tmp)
{
	tmp = list;
	while (tmp)
	{
		if (!ft_strcmp(tmp->line, "##start"))
		{
			while (tmp->line[0] == '#')
				tmp = tmp->next;
			if (tmp)
			{
				arg = ft_strsplit(tmp->line, ' ');
				if (arg[0] && arg[1] && arg[2] && !arg[3])
				{
					if (DR[0]->name)
						ft_memdel((void**)&DR[0]->name);
					DR[0]->name = ft_strdup(arg[0]);
					DR[0]->x = (int)my_atoll(arg[1], list, data, 0);
					DR[0]->y = (int)my_atoll(arg[2], list, data, 0);
					DR[0]->num = 0;
				}
				delete_arg(arg);
				data->used_room < 1 ? data->used_room = 1 : 0;
			}
		}
		tmp = tmp->next;
	}
}

static int		ft_find_info(t_check *list, t_info *data)
{
	int			i;

	i = 2;
	while (list)
	{
		if (ft_strchr(list->line, '-') && !ft_strchr(list->line, ' '))
			break ;
		if (ft_skip_hash(&list, data, &i))
			return (1);
	}
	data->used_room = (size_t)i;
	return (0);
}

int				fill_info(t_check *list, t_info *data)
{
	t_check		*tmp;
	char		**arg;

	arg = NULL;
	tmp = NULL;
	ft_start(list, data, arg, tmp);
	ft_end(list, data, arg, tmp);
	if (ft_find_info(list, data))
		return (1);
	return (0);
}
