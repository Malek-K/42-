/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:49:00 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 20:45:09 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int	lendst;
	unsigned int	lensrc;
	unsigned int	k;

	lendst = 0;
	lensrc = 0;
	k = 0;
	while (dst[lendst])
		lendst++;
	while (src[lensrc])
		lensrc++;
	if (size == 0)
		return (lensrc);
	while (src[k] && ((lendst + k) < (size - 1)))
	{
		dst[lendst + k] = src[k];
		k++;
	}
	dst[lendst + k] = '\0';
	return (lensrc + ((lendst < size) ? lendst : size));
}
