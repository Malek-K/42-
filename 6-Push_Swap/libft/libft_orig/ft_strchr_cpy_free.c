/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_cpy_free.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 18:33:47 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/02 19:05:41 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr_cpy_free(char *s, char c)
{
	char	*cpy;
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[len] && s[len] != c)
		len++;
	if (!s)
		return ((char*)s);
	cpy = (char *)malloc(sizeof(char) * (len + 1));
	if (!cpy)
		return (NULL);
	while (i < len)
	{
		cpy[i] = s[i];
		i++;
	}
	cpy[i] = '\0';
	ft_strdel(&s);
	return (cpy);
}
