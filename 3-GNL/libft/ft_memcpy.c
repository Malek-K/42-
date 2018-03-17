/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:01:09 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/14 16:34:00 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*cpysrc;
	unsigned char	*cpydst;
	size_t			i;

	i = 0;
	cpysrc = (unsigned char*)src;
	cpydst = (unsigned char*)dst;
	while (i < n)
	{
		cpydst[i] = cpysrc[i];
		i++;
	}
	return (dst);
}
