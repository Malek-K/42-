/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_whitespaces.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/14 14:29:32 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/14 15:32:27 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	**ft_row(char **tbl, char *str)
{
	int i;
	int c;

	i = 0;
	c = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		{
			c++;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	if (!(str[i - 1] == ' ' || str[i - 1] == '\t' || str[i - 1] == '\n'))
		c++;
	tbl = (char**)malloc(sizeof(*tbl) * (c + 1));
	tbl[c] = 0;
	return (tbl);
}

char	**ft_collumn(char **tbl, char *str)
{
	int i;
	int c;
	int k;

	i = 0;
	k = 0;
	c = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		i++;
		if (str[i] == ' ' || str[i] == '\t' ||
				str[i] == '\n' || str[i] == '\0')
		{
			tbl[c] = (char*)malloc(sizeof(**tbl) * (k + 1));
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
			k = 0;
			c++;
		}
		k++;
	}
	return (tbl);
}

char	**ft_fill(char **tbl, char *str)
{
	int i;
	int c;
	int j;

	i = 0;
	c = 0;
	j = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
		i++;
	while (str[i] != '\0')
	{
		tbl[c][j] = str[i];
		i++;
		j++;
		if (str[i] == ' ' || str[i] == '\t' ||
				str[i] == '\n' || str[i] == '\0')
		{
			tbl[c][j] = '\0';
			c++;
			j = 0;
			while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n')
				i++;
		}
	}
	return (tbl);
}

char	**ft_split_whitespaces(char *str)
{
	char **arr;

	arr = NULL;
	arr = ft_row(arr, str);
	arr = ft_collumn(arr, str);
	arr = ft_fill(arr, str);
	return (arr);
}
