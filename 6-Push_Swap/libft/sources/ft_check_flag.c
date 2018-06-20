/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_flag.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/03 18:30:53 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/05 14:17:08 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_check_flag(char *cpy, t_data *arg)
{
	arg->flag_ptr = cpy;
	if (ft_strchr("sSpdDioOuUxXcCbnfF", *cpy) != NULL && *cpy)
	{
		arg->f_field = 1;
		arg->flag = *cpy;
	}
	else
		arg->flag = *cpy;
}
