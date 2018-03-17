/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 12:07:43 by alima             #+#    #+#             */
/*   Updated: 2017/11/09 15:07:40 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *ndl)
{
	int i;
	int j;
	int k;

	i = 0;
	if (ft_strlen(str) == 0 && ft_strlen(ndl) == 0)
		return ((char *)str);
	while (str[i])
	{
		j = 0;
		k = i;
		while (str[k] == ndl[j] && str[k] != '\0' && ndl[j] != '\0')
		{
			k++;
			j++;
		}
		if (ndl[j] == '\0')
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}
