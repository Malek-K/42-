/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/19 18:40:33 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/19 18:50:12 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_count_if(char **tab, int (*f)(char*))
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (tab[i])
	{
		if (f(tab[i]) == 1)
			j++;
		i++;
	}
	return (j);
}
