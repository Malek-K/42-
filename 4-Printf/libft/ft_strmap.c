/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 17:01:05 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 14:49:15 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	int		i;
	int		len;
	char	*s2;

	if (!s)
		return (0);
	i = 0;
	len = ft_strlen(s);
	s2 = (char *)malloc(sizeof(f(s[i])) * (len + 1));
	if (!s2)
		return (NULL);
	while (s[i])
	{
		s2[i] = f(s[i]);
		i++;
	}
	s2[i] = '\0';
	return (s2);
}
