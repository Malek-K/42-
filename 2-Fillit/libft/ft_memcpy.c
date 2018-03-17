/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ftmemcpy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:53:54 by alima             #+#    #+#             */
/*   Updated: 2017/11/10 17:45:07 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*sr;
	unsigned char	*ds;

	i = 0;
	sr = (unsigned char *)src;
	ds = (unsigned char *)dest;
	while (i < n)
	{
		ds[i] = sr[i];
		i++;
	}
	return (dest);
}
