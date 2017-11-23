/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 16:12:30 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/09 16:13:00 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(char *s1)
{
	char	*cpy;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (s1[len])
		len++;
	cpy = (char*)malloc(sizeof(*cpy) * (len + 1));
	if (cpy == NULL)
		return (0);
	while (s1[i])
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}
