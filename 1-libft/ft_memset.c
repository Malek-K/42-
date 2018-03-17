/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 15:13:48 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/13 16:21:18 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	unsigned char	*str;

	c = (unsigned char)c;
	str = (unsigned char*)b;
	while (len > 0)
	{
		str[len - 1] = c;
		len--;
	}
	return (b);
}
