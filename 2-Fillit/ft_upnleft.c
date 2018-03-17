/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_upnleft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 21:00:30 by mkamel            #+#    #+#             */
/*   Updated: 2017/12/07 17:47:29 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_char_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

static char	*ft_up(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i++] != '#')
	{
		if (str[i] == '\n')
			k++;
	}
	i = 0;
	while (str[i++])
	{
		if (i >= 5 && str[i] == '#')
			ft_char_swap(&str[i], &str[i - (k * 5)]);
	}
	return (str);
}

static char	*ft_left(char *str)
{
	int		i;
	int		k;

	i = 0;
	k = 0;
	while (str[i] != '#')
		i++;
	k = i % 5;
	while (str[i++])
	{
		if (str[i] == '#' && k > i % 5)
			k = i % 5;
	}
	if (k > 0)
	{
		i = 0;
		while (str[i++])
		{
			if (str[i] == '#')
				ft_char_swap(&str[i], &str[i - k]);
		}
	}
	return (str);
}

char		*ft_upnleft(char *str)
{
	char	*ulstr;

	ulstr = ft_up(str);
	ulstr = ft_left(str);
	return (ulstr);
}
