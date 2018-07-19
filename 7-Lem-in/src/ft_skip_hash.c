/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_skip_hash.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 18:04:30 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/29 14:41:23 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define LL (*list)->line

static int		check_new_info(t_info *data, char *name, int x, int y)
{
	int		i;

	i = 0;
	while (data->room[i])
	{
		if (!ft_strcmp(data->room[i]->name, name))
		{
			data->room[i]->x = x;
			data->room[i]->y = y;
			return (0);
		}
		else if (data->room[i]->x == x && data->room[i]->y == y)
			return (1);
		i++;
	}
	return (0);
}

static int		ft_fill_room(t_check *list, t_info *data, t_room **room, int i)
{
	char		**arg;

	arg = ft_strsplit(list->line, ' ');
	if (check_new_info(data, arg[0], ft_atoi(arg[1]), ft_atoi(arg[2])))
	{
		delete_arg(arg);
		return (1);
	}
	(*room)->name = ft_strdup(arg[0]);
	(*room)->x = (int)my_atoll(arg[1], list, data, 0);
	(*room)->y = (int)my_atoll(arg[2], list, data, 0);
	(*room)->num = i;
	delete_arg(arg);
	return (0);
}

static void		ft_deal_start_n_end(t_check **list)
{
	while (LL[0] == '#')
		(*list) = (*list)->next;
	(*list) = (*list)->next;
}

int				ft_skip_hash(t_check **list, t_info *data, int *i)
{
	int			j;
	int			k;

	j = 0;
	k = 0;
	if (!ft_strcmp(LL, "##start") || !ft_strcmp(LL, "##end"))
		ft_deal_start_n_end(list);
	else if (LL[0] == '#' && LL[1] != '#')
		(*list) = (*list)->next;
	else
	{
		while (LL[j])
			if (LL[j++] == ' ')
				k++;
		if (k != 2)
			(*list) = (*list)->next;
		else
		{
			if (ft_fill_room((*list), data, &data->room[*i], *i))
				return (1);
			*i += 1;
			(*list) = (*list)->next;
		}
	}
	return (0);
}
