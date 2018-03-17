/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:08:31 by alima             #+#    #+#             */
/*   Updated: 2017/11/16 12:34:37 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_len(int n)
{
	int count;

	count = 0;
	if (n < 0)
	{
		n *= -1;
		count++;
	}
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count++);
}

static void	ft_fill(char *s, int n, int len)
{
	s[len] = '\0';
	len--;
	while (len >= 0)
	{
		s[len] = (n % 10) + '0';
		len--;
		n /= 10;
	}
}

char		*ft_itoa(int n)
{
	char	*s;
	int		len;
	int		neg;

	if (!n)
		return (ft_strdup("0"));
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	neg = 0;
	len = ft_len(n);
	s = (char *)malloc(sizeof(char) * len + 1);
	if (!s)
		return (NULL);
	if (n < 0)
	{
		n = -n;
		neg += 1;
	}
	ft_fill(s, n, len);
	if (neg > 0)
		s[0] = '-';
	return (s);
}
