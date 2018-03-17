/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:51:32 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/19 21:11:48 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;

	i = 0;
	if (length == 0)
		return (1);
	while (i + 1 < length && f(tab[i], tab[i + 1]) >= 0)
		i++;
	if (i + 1 == length)
		return (1);
	i = 0;
	while (i + 1 < length && f(tab[i], tab[i + 1]) <= 0)
		i++;
	if (i + 1 == length)
		return (1);
	return (0);
}
