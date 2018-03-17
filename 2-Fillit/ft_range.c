/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 14:30:12 by alima             #+#    #+#             */
/*   Updated: 2017/12/08 14:30:17 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void		ft_range_coord(t_lst *first)
{
	t_lst	*list;

	list = first;
	while (list->next != NULL)
	{
		if (list->y[0] > 0)
		{
			list->y[3] = list->y[3] - list->y[0];
			list->y[2] = list->y[2] - list->y[0];
			list->y[1] = list->y[1] - list->y[0];
			list->y[0] = list->y[0] - list->y[0];
		}
		list = list->next;
	}
}

static void		ft_coord(t_lst *first)
{
	int		i;
	int		j;
	t_lst	*list;

	list = first;
	while (list->next != NULL)
	{
		i = 0;
		j = 0;
		while (list->str[i] != '\0')
		{
			if (list->str[i] == '#')
			{
				list->x[j] = i / 5;
				list->y[j] = i % 5;
				j++;
			}
			i++;
		}
		list = list->next;
	}
	list->next = NULL;
}

t_lst			*ft_range(char *buf)
{
	t_lst	*first;
	t_lst	*tmp;
	int		i;
	char	letter;

	if (!(first = (t_lst *)malloc(sizeof(t_lst))))
		return (NULL);
	tmp = first;
	i = 0;
	letter = 'A';
	while (buf[i] != '\0')
	{
		tmp->str = ft_strsub(buf, i, 20);
		ft_upnleft(tmp->str);
		tmp->letter = letter++;
		if (!(tmp->next = (t_lst *)malloc(sizeof(t_lst))))
			return (NULL);
		tmp = tmp->next;
		i += 21;
	}
	tmp = NULL;
	ft_coord(first);
	ft_range_coord(first);
	return (first);
}
