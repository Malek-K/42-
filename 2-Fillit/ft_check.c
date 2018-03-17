/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 17:35:26 by alima             #+#    #+#             */
/*   Updated: 2017/12/07 18:44:05 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_more(char *tmp, int *i, int *diz, int *per)
{
	if (tmp[*i] == '#')
	{
		*diz += 1;
		return (0);
	}
	if (tmp[*i] == '.')
	{
		*per += 1;
		return (0);
	}
	if (tmp[*i] == '\n' && *i % 5 != 4 && *i != 20)
		return (1);
	if (tmp[*i] == '\n' && tmp[*i - 1] == '\n' && tmp[*i + 1] == '\0')
		return (1);
	return (0);
}

static int	check_form(char *buff)
{
	int i;
	int link;

	i = 0;
	link = 0;
	while (i != 20)
	{
		if (buff[i] == '#')
		{
			if (buff[i + 1] == '#')
				link++;
			if (i < 15 && buff[i + 5] == '#')
				link++;
			if (i > 0 && buff[i - 1] == '#')
				link++;
			if (i > 4 && buff[i - 5] == '#')
				link++;
		}
		i++;
	}
	if (link == 8)
		link = 6;
	return (link);
}

int			ft_check(char *buf)
{
	int		i;
	char	*tmp;
	int		diz;
	int		per;

	if (!buf)
		return (1);
	diz = 0;
	per = 0;
	tmp = buf;
	i = 0;
	while (tmp[i] == '.' || tmp[i] == '#' || tmp[i] == '\n' || tmp[i])
	{
		if (i == 20 && tmp[i + 1] != '\0')
		{
			tmp = tmp + i + 1;
			i = 0;
		}
		if (check_more(tmp, &i, &diz, &per) == 1 || check_form(tmp) != 6)
			return (1);
		i++;
	}
	if (tmp[i] != '\0' || diz % 4 != 0 || per % 4 != 0 || diz * 3 != per)
		return (1);
	return (0);
}
