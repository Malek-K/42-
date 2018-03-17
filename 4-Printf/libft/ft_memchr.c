/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 21:01:39 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 00:12:00 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char		*cpy;
	size_t				i;

	cpy = (unsigned char*)s;
	c = (unsigned char)c;
	i = 0;
	if (!n)
		return (NULL);
	while (cpy[i] != c && (i < n - 1))
		i++;
	if (cpy[i] == c)
		return (cpy + i);
	else
		return (NULL);
}
