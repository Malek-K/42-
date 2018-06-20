/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:10:02 by mkamel            #+#    #+#             */
/*   Updated: 2018/02/01 15:18:57 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		ft_len(unsigned long long int n, int base)
{
	size_t			count;

	count = 0;
	if (n == 0)
		count++;
	while (n != 0)
	{
		n /= base;
		count++;
	}
	return (count++);
}

static void			ft_fill(char *s, unsigned long long int n, \
		size_t len, int base)
{
	while (len--)
	{
		if ((n % base) < 10)
			s[len] = (n % base) + '0';
		else
			s[len] = (n % base) + 'A' - 10;
		n /= base;
	}
}

char				*ft_utoa_base(unsigned long long int value, int base)
{
	size_t			len;
	char			*str;

	if (base < 2)
		return (NULL);
	len = ft_len(value, base);
	str = ft_strnew(len);
	ft_fill(str, value, len, base);
	free(str);
	return (str);
}
