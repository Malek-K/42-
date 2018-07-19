/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_function.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 19:21:50 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/28 16:43:13 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		my_error(t_check *list, t_info *data, int type)
{
	if (type == 1)
	{
		ft_putendl_fd("ERROR : Overflow or Underflow.", 2);
		delete_list(&list);
		delete_info(&data);
	}
	else if (type == 2)
		ft_putendl_fd("ERROR : Incorrect input in room name.", 2);
	else if (type == 3)
		ft_putendl_fd("ERROR : Start room is End room.", 2);
	else if (type == 4)
		ft_putendl_fd("ERROR : Two rooms with same coordinates.", 2);
}

long		my_atoll(const char *str, t_check *list, t_info *data, long nb)
{
	long	signe;
	int		index;

	signe = 1;
	index = 0;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			signe = -1;
		str++;
	}
	while (*str == '0')
		str++;
	while (str[index] >= '0' && str[index] <= '9')
		nb = nb * 10 + (str[index++] - '0');
	if (signe * nb < INT_MIN || signe * nb > INT_MAX || index > 11 ||
			str[index - 1] == '-' || str[index - 1] == '+' ||
			str[index] == '-' || str[index] == '+')
	{
		my_error(list, data, 1);
		exit(1);
	}
	return (signe * nb);
}
