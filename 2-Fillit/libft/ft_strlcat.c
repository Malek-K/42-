/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 12:49:57 by alima             #+#    #+#             */
/*   Updated: 2017/11/13 13:43:58 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	i;
	size_t	j;

	dlen = ft_strlen(dst);
	j = ft_strlen(src);
	if (size <= dlen)
		return (j + size);
	i = dlen;
	while (*src && i != size - 1)
	{
		dst[i] = *src;
		src++;
		i++;
	}
	dst[i] = '\0';
	return (dlen + j);
}
