/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 17:49:51 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 18:41:15 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int		i;

	c = (unsigned char)c;
	i = 0;
	while (s[i] && s[i] != c)
		i++;
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (NULL);
}
