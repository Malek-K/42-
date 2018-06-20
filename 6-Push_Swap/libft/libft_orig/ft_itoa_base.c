/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/30 16:09:15 by mkamel            #+#    #+#             */
/*   Updated: 2018/02/01 15:18:51 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t				ft_len(long long int n, int base)
{
	size_t					count;

	count = 0;
	if (n == 0)
		count++;
	if (n < 0 && base == 10)
	{
		n = -n;
		count++;
	}
	while ((unsigned long long int)n != 0)
	{
		n = (unsigned long long int)n / base;
		count++;
	}
	return (count++);
}

static void					ft_fill(char *s, unsigned long long int n, \
		int len, int base)
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

char						*ft_itoa_base(long long int value, int base)
{
	size_t					len;
	int						neg;
	unsigned long long int	u_value;
	char					*str;

	if (base < 2)
		return (NULL);
	neg = 0;
	len = ft_len(value, base);
	str = ft_strnew(len + 1);
	if (value < 0 && base == 10)
	{
		value = -value;
		neg += 1;
	}
	else
		u_value = (unsigned long long int)value;
	base == 10 ? ft_fill(str, value, len, base) : \
	ft_fill(str, u_value, len, base);
	if (neg > 0)
		str[0] = '-';
	free(str);
	return (str);
}
