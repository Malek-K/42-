/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_integer_table.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/05 15:28:28 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/05 17:30:37 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_integer_table(int *tab, int size)
{
	int		pos;
	int		min;
	int		tmp;

	min = 0;
	while (min <= size)
	{
		pos = 0;
		while (pos <= (size - min))
		{
			pos++;
			if (tab[min] <= tab[pos + min])
			{
				tmp = min;
				min = pos;
				pos = tmp;
			}
		}
		min++;
	}
}
