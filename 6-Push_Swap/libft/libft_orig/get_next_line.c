/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/11 15:53:00 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/12 23:42:48 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

static t_line		*ft_check_fd(int fd, t_line **block)
{
	t_line			*tmp_block;
	t_line			*prev_tmp;

	tmp_block = *block;
	prev_tmp = NULL;
	while (tmp_block != NULL)
	{
		if (tmp_block->fd == fd)
			return (tmp_block);
		prev_tmp = tmp_block;
		tmp_block = tmp_block->next;
	}
	if (!(tmp_block = (t_line*)malloc(sizeof(t_line))))
		return (NULL);
	tmp_block->fd = fd;
	tmp_block->tmp = ft_strnew(0);
	tmp_block->next = NULL;
	if (prev_tmp != NULL)
		prev_tmp->next = tmp_block;
	else
		*block = tmp_block;
	return (tmp_block);
}

static int			ft_check_line(char *str, int size)
{
	int				i;

	i = 0;
	while (i < size)
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static void			ft_check_tmp(t_line *block, char ***line)
{
	char			*tmp;
	char			*tmpline;

	if (block->tmp != NULL)
	{
		tmp = ft_strdup(block->tmp);
		if (ft_check_line(tmp, ft_strlen(tmp)) == 1)
		{
			ft_strdel(&block->tmp);
			tmpline = ft_strchr_cpy(tmp, '\n');
			block->tmp = ft_strdup(ft_strchr(tmp, '\n') + 1);
			**line = ft_strdup(tmpline);
			ft_strdel(&tmp);
			ft_strdel(&tmpline);
		}
		else if (ft_check_line(tmp, ft_strlen(tmp)) == 0)
		{
			tmpline = ft_strchr_cpy_free(tmp, '\0');
			**line = ft_strdup_free(tmpline);
			ft_strdel(&block->tmp);
		}
	}
	else
		**line = ft_strnew(0);
}

static int			ft_line(int size, char *buf, char **line, t_line *block)
{
	char			*tmp;

	while (size > 0 && ft_check_line(buf, size) == 0)
	{
		if (line[0] == '\0')
			*line = ft_strdup_free(buf);
		else
			*line = ft_strjoin_free(*line, buf, 1);
		size = read(block->fd, buf, BUFF_SIZE);
		if (size != BUFF_SIZE)
			buf[size] = '\0';
	}
	if (ft_check_line(buf, size) == 1)
	{
		tmp = ft_strdup(ft_strchr(buf, '\n') + 1);
		block->tmp = ft_strdup_free(tmp);
		tmp = ft_strchr_cpy_free(buf, '\n');
		if (line[0] == '\0')
			*line = ft_strdup_free(tmp);
		else
			*line = ft_strjoin_free(*line, tmp, 3);
		return (1);
	}
	return (0);
}

int					get_next_line(const int fd, char **line)
{
	static t_line	*start;
	t_line			*block;
	char			*buf;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	block = ft_check_fd(fd, &start);
	ft_check_tmp(block, &line);
	if (block->tmp != NULL)
		return (1);
	if (!(buf = ft_strnew(BUFF_SIZE)))
		return (-1);
	start->size = read(fd, buf, BUFF_SIZE);
	if (start->size < 0)
		return (-1);
	if (ft_line(start->size, buf, line, block) == 1)
		return (1);
	else if (*line[0] != '\0')
	{
		free(buf);
		return (1);
	}
	free(buf);
	return (0);
}
