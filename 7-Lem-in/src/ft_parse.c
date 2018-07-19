/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/07 15:56:07 by mkamel            #+#    #+#             */
/*   Updated: 2018/06/27 19:43:37 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		fill_list(char *line, t_check **list)
{
	t_check		*begin;
	t_check		*new;

	begin = *list;
	if (begin->line == NULL)
	{
		(*list)->line = ft_strdup(line);
		(*list)->next = NULL;
	}
	else
	{
		if (!(new = (t_check*)ft_memalloc(sizeof(t_check))))
			return (1);
		while (begin->next != NULL)
			begin = begin->next;
		new->line = ft_strdup(line);
		new->next = NULL;
		begin->next = new;
	}
	return (0);
}

void			ft_parse(int fd, t_check *list, t_info *data)
{
	int			ret;
	char		*line;

	while (get_next_line(fd, &line) > 0)
	{
		if (line && fill_list(line, &list))
		{
			ft_memdel((void**)&line);
			return ;
		}
		ft_memdel((void**)&line);
	}
	ret = ft_check_list(list, data, 0, 0);
	if (ret)
		my_error(list, data, ret);
	else
		ft_create_path(data, list);
	if (close(fd))
	{
		ft_putstr_fd("ERROR : fail to close fd.\n", 2);
		exit(1);
	}
}
