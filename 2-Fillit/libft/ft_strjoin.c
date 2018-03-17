/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:09:38 by alima             #+#    #+#             */
/*   Updated: 2017/11/14 14:26:08 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	int		len1;
	int		len2;
	char	*new;
	int		i;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	new = (char *)malloc(sizeof(char *) * (len1 + len2 + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (i != len1)
	{
		new[i++] = *s1;
		s1++;
	}
	while (i != (len1 + len2))
	{
		new[i++] = *s2;
		s2++;
	}
	new[i] = '\0';
	return ((char *)new);
}
