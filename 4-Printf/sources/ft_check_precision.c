/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_precision.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 15:51:33 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 20:34:16 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static int		ft_check_nb(char *end, t_data *arg)
{
	char		*check;

	check = end;
	while (*check != arg->flag)
	{
		if (ft_isdigit(*check))
			return (1);
		check++;
	}
	return (0);
}

void			ft_check_precision(char *cpy, t_data *arg)
{
	char		*end;
	int			p;

	end = cpy - 1;
	while (*end && *end != '.' && *end != '%')
		end--;
	if (*end == '.' && *(end + 1) != '*')
	{
		arg->p_field = 1;
		if (ft_check_nb(end, arg) == 1)
			arg->precision = ft_atoi(end + 1);
		else
			arg->precision = 0;
	}
	p = arg->precision;
	arg->precision = (p < 0) ? -arg->precision : arg->precision;
	if (ft_strchr("sScCdDixXuUoOpbfF", arg->flag) == NULL)
	{
		arg->precision = 0;
		arg->p_field = 0;
	}
}
