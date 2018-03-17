/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:49:01 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 14:47:23 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	j;
	size_t	k;

	if (!(s1 && s2))
		return (0);
	cat = (char*)malloc(sizeof(*cat) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!cat)
		return (NULL);
	j = 0;
	k = 0;
	while (s1[j])
	{
		cat[j] = s1[j];
		j++;
	}
	while (s2[k])
	{
		cat[j] = s2[k];
		j++;
		k++;
	}
	cat[j] = '\0';
	return (cat);
}
