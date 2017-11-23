/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 18:46:51 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/13 22:18:35 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	lendst;
	unsigned int	lensrc;
	unsigned int	k;

	lendst = 0;
	lensrc = 0;
	while (dest[lendst])
		lendst++;
	while (src[lensrc])
		lensrc++;
	if (size < lensrc)
		return (lensrc);
	else
	{
		k = 0;
		while (src[k] && k < size - 1)
		{
			dest[k] = src[k];
			k++;
		}
	}
	dest[k] = '\0';
	return (lensrc);
}
