/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_concat_params.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/13 14:03:14 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/18 15:02:06 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(int argc, char **argv)
{
	int		i;
	int		j;
	int		len;

	i = 1;
	len = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			j++;
			len++;
		}
		i++;
	}
	return (len);
}

char	*ft_concat_params(int argc, char **argv)
{
	int		i;
	int		j;
	int		z;
	char	*str;

	z = ft_strlen(argc, argv) + argc;
	str = (char *)malloc(sizeof(*str) * (z + 1));
	i = 1;
	j = 0;
	while (i < argc)
	{
		z = 0;
		while (argv[i][z] != '\0')
			str[j++] = argv[i][z++];
		str[j++] = '\n';
		i++;
	}
	str[j - 1] = 0;
	return (str);
}
