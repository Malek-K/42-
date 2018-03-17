/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 14:33:24 by alima             #+#    #+#             */
/*   Updated: 2017/11/21 16:24:12 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(const char *s)
{
	unsigned int	start;
	int				stop;

	if (!s)
		return (NULL);
	start = 0;
	stop = ft_strlen(s) - 1;
	while ((s[start] == ' ' || s[start] == '\n' || s[start] == '\t')
			&& s[start])
		start++;
	while ((s[stop] == ' ' || s[stop] == '\n' || s[stop] == '\t')
			&& stop > (int)start)
		stop--;
	return (ft_strsub(s, start, (stop - start + 1)));
}
