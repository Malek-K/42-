/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_start_n_end.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/22 15:42:31 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/28 15:18:29 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_check_tmp(t_check *list, t_check *tmp, t_info *data)
{
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->line, "##start"))
		{
			while (!(ft_strchr(tmp->line, ' ')) && tmp->next)
				tmp = tmp->next;
			if (tmp->line && ft_strchr(tmp->line, ' '))
				data->i_start = 1;
		}
		tmp && tmp->next ? tmp = tmp->next : 0;
	}
	tmp = list;
	while (tmp->next)
	{
		if (!ft_strcmp(tmp->line, "##end"))
		{
			while (!(ft_strchr(tmp->line, ' ')) && tmp->next)
				tmp = tmp->next;
			if (tmp->line && ft_strchr(tmp->line, ' '))
				data->i_end = 1;
		}
		tmp && tmp->next ? tmp = tmp->next : 0;
	}
}

int				ft_check_start_n_end(t_check *list, t_info *data)
{
	t_check		*tmp;

	tmp = list;
	ft_check_tmp(list, tmp, data);
	if (!data->i_start || !data->i_end || !data->ant)
	{
		if (!data->ant)
			ft_putendl_fd("ERROR : No Ant Number Input.", 2);
		else if (!data->i_start && data->i_end)
			ft_putendl_fd("ERROR : No correct Start command.", 2);
		else if (!data->i_end && data->i_start)
			ft_putendl_fd("ERROR : No correct End command.", 2);
		else
			ft_putendl_fd("ERROR : No correct Start and End command.", 2);
		return (-1);
	}
	return (0);
}
