/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_param_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/17 14:54:10 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/18 21:56:43 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_par.h"
#include <stdlib.h>

int					ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char				*ft_strdup(char *src)
{
	int		len;
	int		i;
	char	*cpy;

	len = 0;
	i = 0;
	while (src[len])
		len++;
	if (!(cpy = (char*)malloc(sizeof(*cpy) * (len + 1))))
		return (NULL);
	while (src[i])
	{
		cpy[i] = src[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_par	*ft_param_to_tab(int ac, char **av)
{
	int			i;
	t_stock_par	*arr;
	t_stock_par *ret;

	i = 0;
	if (!(arr = (t_stock_par*)malloc(sizeof(t_stock_par) * (ac + 1))))
		return (NULL);
	ret = arr;
	while (i < ac)
	{
		arr->size_param = ft_strlen(av[i]);
		arr->str = av[i];
		arr->copy = ft_strdup(av[i]);
		arr->tab = ft_split_whitespaces(av[i]);
		i++;
		arr++;
	}
	arr->str = 0;
	return (ret);
}
