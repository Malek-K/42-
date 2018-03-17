/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 12:12:05 by alima             #+#    #+#             */
/*   Updated: 2017/12/05 11:50:30 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *octet, int c, size_t len)
{
	unsigned char *o;

	o = octet;
	while (len--)
	{
		*o++ = (unsigned char)c;
	}
	return (octet);
}
