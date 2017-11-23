/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 20:09:11 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/17 16:14:51 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*cpys1;
	unsigned char	*cpys2;
	size_t			i;

	cpys1 = (unsigned char *)s1;
	cpys2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < (n - 1) && cpys1[i] == cpys2[i])
		i++;
	if (cpys1[i] != cpys2[i])
		return (cpys1[i] - cpys2[i]);
	else
		return (0);
}
