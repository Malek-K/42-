/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 19:12:46 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/18 19:16:27 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	char	*zone;

	zone = (char*)malloc(sizeof(*zone) * size);
	if (!zone)
		return (NULL);
	zone = ft_memset(zone, 0, size);
	return (zone);
}
