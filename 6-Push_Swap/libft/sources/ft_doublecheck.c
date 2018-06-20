/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_doublecheck.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/06 16:38:58 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/08 16:24:40 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_doublecheck(t_data *arg)
{
	if (ft_strchr("xXoOpb", arg->flag) == NULL && arg->hash == 1)
		arg->hash = 0;
	if (ft_strchr("pb", arg->flag) && arg->hash != 1)
		arg->hash = 1;
	if (ft_strchr("dDixXuUoOpbfF", arg->flag) && (arg->minus != 0 || \
				arg->p_field != 0) && arg->zero == 1)
		arg->zero = 0;
	if ((ft_strchr("dDfFi", arg->flag) == NULL || arg->plus != 0) \
			&& arg->space == 1)
		arg->space = 0;
	if (ft_strchr("cC%", arg->flag) && arg->precision)
	{
		arg->precision = 0;
		arg->p_field = 0;
	}
	if ((ft_strchr("dDifF", arg->flag) == NULL && arg->plus != 0))
		arg->plus = 0;
}
