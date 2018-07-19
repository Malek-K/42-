/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_struct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/14 17:43:28 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/28 15:10:04 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		delete_link(t_link **link)
{
	t_link		*tmp;

	if (!link || !(*link))
		return ;
	tmp = (*link);
	while (tmp)
	{
		tmp = (*link)->next;
		ft_memdel((void**)link);
		(*link) = tmp;
	}
}

void			delete_arg(char **arg)
{
	int			i;

	i = 0;
	if (!arg && !*arg)
		return ;
	while (arg[i])
		ft_memdel((void**)&arg[i++]);
	free((void*)arg);
	arg = NULL;
}

void			delete_info(t_info **data)
{
	size_t		i;

	i = 0;
	if ((*data)->room)
	{
		while (i <= (*data)->nb_room)
		{
			if ((*data)->room[i]->links)
				delete_link(&(*data)->room[i]->links);
			ft_memdel((void**)&(*data)->room[i]->name);
			ft_memdel((void**)&(*data)->room[i]);
			i++;
		}
	}
	ft_memdel((void*)&(*data)->room);
	ft_memdel((void*)&(*data));
}

void			delete_list(t_check **list)
{
	t_check		*tmp;

	if ((*list))
	{
		tmp = (*list);
		while (tmp)
		{
			tmp = tmp->next;
			ft_memdel((void**)&(*list)->line);
			ft_memdel((void**)list);
			(*list) = tmp;
		}
	}
}
