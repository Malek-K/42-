/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:01:09 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/16 14:28:46 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	const unsigned char	*cpysrc;
	unsigned char		*cpydst;
	size_t				i;

	cpysrc = (const unsigned char*)src;
	cpydst = (unsigned char*)dst;
	i = 0;
	if (dst > src)
	{
		while (len > 0)
		{
			cpydst[len - 1] = cpysrc[len - 1];
			len--;
		}
	}
	else
	{
		while (i < len)
		{
			cpydst[i] = cpysrc[i];
			i++;
		}
	}
	return (dst);
}
