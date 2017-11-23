/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/12 12:06:04 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/14 20:20:25 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
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
	if (size + lensrc <= lendst + lensrc)
		return (size + lensrc);
	else
	{
		k = 0;
		while (src[k] && k < size - lendst - 1)
		{
			dest[lensrc + k] = src[k];
			k++;
		}
	}
	dest[lensrc + k] = '\0';
	return (lensrc + k);
}
