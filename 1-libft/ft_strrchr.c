/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:15:38 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/16 18:17:07 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	c = (unsigned char)c;
	i = ft_strlen(s);
	while (i > 0 && s[i] != c)
		i--;
	if (s[i] == c)
		return ((char*)s + i);
	else
		return (NULL);
}
