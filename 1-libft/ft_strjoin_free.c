/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/21 14:59:04 by mkamel            #+#    #+#             */
/*   Updated: 2018/01/02 16:36:13 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free(char **s1, char **s2, int order)
{
	if (order == 1)
		ft_strdel(s1);
	if (order == 2)
		ft_strdel(s2);
	if (order == 3)
	{
		ft_strdel(s1);
		ft_strdel(s2);
	}
}

char	*ft_strjoin_free(char *s1, char *s2, int order)
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
		cat[j++] = s2[k++];
	cat[j] = '\0';
	if (order == 1 || order == 2 || order == 3)
		ft_free(&s1, &s2, order);
	return (cat);
}
