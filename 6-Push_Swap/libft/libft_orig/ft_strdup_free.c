/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_free.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:58:40 by mkamel            #+#    #+#             */
/*   Updated: 2017/12/21 18:35:12 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_free(char *s1)
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
	ft_strdel(&s1);
	return (cpy);
}
