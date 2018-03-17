/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtrim.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:45:13 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/22 14:30:55 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	size_t	fin;
	size_t	deb;
	size_t	len;
	char	*cpy;

	if (!s)
		return (0);
	fin = ft_strlen(s) - 1;
	deb = 0;
	while (s[deb] && (s[deb] == ' ' || s[deb] == '\t' || s[deb] == '\n'))
		deb++;
	while (deb < fin && (s[fin] == ' ' || s[fin] == '\t' || s[fin] == '\n'))
		fin--;
	len = fin - deb + 1;
	cpy = ft_strsub(s, deb, len);
	return (cpy);
}
