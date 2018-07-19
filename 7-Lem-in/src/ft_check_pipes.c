/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_pipes.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/08 14:55:39 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/29 12:48:16 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"
#define DR datas->room
#define LL list->line

static int		ft_check_names(char *line, t_info *datas, size_t len, size_t i)
{
	int			check_1;
	int			check_2;

	check_1 = 0;
	check_2 = 0;
	while (line[len] != '-')
		len++;
	if (len == 0 || line[len + 1] == '\0' ||
			(ft_strncmp(line, line + len + 1, len) == 0 &&
				ft_strlen(line + len + 1) == len))
		return (-1);
	while (i < datas->nb_room)
	{
		ft_strncmp(DR[i]->name, line, len) == 0 ? check_1 = 1 : 0;
		ft_strcmp(DR[i]->name, line + len + 1) == 0 ? check_2 = 1 : 0;
		if (check_1 == 1 && check_2 == 1)
			return (0);
		i++;
	}
	return (-1);
}

size_t			ft_check_pipes(t_check *list, t_info *datas, int dash, size_t j)
{
	int			i;

	while (list && ++j)
	{
		dash = 0;
		i = 0;
		while (!ft_strncmp(list->line, "#", 1))
		{
			if (!(list->next))
				return (0);
			list = list->next;
		}
		while (list->line[i])
		{
			if (ft_strchr(" \n\t\v\f\r", list->line[i]) || dash > 1)
				break ;
			else if (ft_strchr("-", list->line[i]))
				dash++;
			i++;
		}
		if (LL[i] || dash != 1 || ft_check_names(LL, datas, 0, 0) != 0)
			return (j);
		list = list->next;
	}
	return (0);
}
