/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 17:45:19 by alima             #+#    #+#             */
/*   Updated: 2017/11/10 17:50:14 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	const char	*tmp_s;
	char		*tmp_d;

	tmp_s = (const char *)src;
	tmp_d = (char *)dest;
	if (tmp_s < tmp_d)
	{
		while (n--)
			tmp_d[n] = tmp_s[n];
	}
	else
		ft_memcpy(tmp_d, tmp_s, n);
	return (tmp_d);
}
