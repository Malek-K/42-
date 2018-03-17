/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:46:53 by alima             #+#    #+#             */
/*   Updated: 2017/11/16 14:08:08 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char	*new_s;
	int		i;

	if (!s)
		return (NULL);
	if (len == 0)
		return (ft_strdup(""));
	i = 0;
	new_s = (char *)malloc(len + 1);
	if (!new_s)
		return (NULL);
	new_s[len] = '\0';
	len--;
	while (len != 0)
	{
		new_s[i++] = s[start++];
		len--;
	}
	new_s[i] = s[start];
	return (new_s);
}
