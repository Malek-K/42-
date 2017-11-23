/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_antidote.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/08 00:09:30 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/08 10:17:56 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_antidote(int i, int j, int k)
{
	int		max;
	int		med;

	if (i <= k && j <= k)
		max = k;
	if (i <= j && k <= j)
		max = j;
	if (j <= i && k <= i)
		max = i;
	if (!(k == i || k == j || i == j))
	{
		med = max - 1;
		while (!(med == i || med == j || med == k))
			med--;
		return (med);
	}
	if (k == i || k == j)
		return (k);
	if (j == i || j == k)
		return (j);
	if (i == j || i == k)
		return (i);
	return (0);
}
