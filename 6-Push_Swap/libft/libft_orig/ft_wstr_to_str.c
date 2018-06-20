/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wstr_to_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/31 16:19:51 by mkamel            #+#    #+#             */
/*   Updated: 2018/01/31 18:53:22 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				*ft_wstr_to_str(const wchar_t *wstr)
{
	char			*ret;
	char			*wchar;
	unsigned int	i;

	if (wstr == NULL)
		return (NULL);
	else
	{
		ret = ft_strnew(ft_wstrlen(wstr) * 4);
		i = 0;
		while (wstr[i])
		{
			wchar = ft_wchar_to_str(wstr[i]);
			ret = ft_strcat(ret, wchar);
			i++;
		}
		free(ret);
		return (ret);
	}
}
