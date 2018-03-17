/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:13:11 by alima             #+#    #+#             */
/*   Updated: 2017/11/09 17:34:29 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hst, const char *ndl, int len)
{
	int i;
	int j;
	int k;

	i = 0;
	while (hst[i] && i < len)
	{
		j = 0;
		k = i;
		while (hst[k] == ndl[j] && hst[k] && ndl[j] && k < len)
		{
			k++;
			j++;
		}
		if (ndl[j] == '\0')
			return ((char *)hst + i);
		i++;
	}
	return (NULL);
}
