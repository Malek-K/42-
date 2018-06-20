/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:39:49 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 22:05:55 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

void	ft_checks(va_list *ap, va_list *bp, const char **format, t_data *arg)
{
	char	*cpy;

	cpy = (char*)(*format) + 1;
	while (*cpy && ft_strchr("#0 -+ 0123456789 . hlLqjzt * $ '", *cpy) != NULL)
	{
		ft_check_prepends(ap, bp, cpy, arg);
		ft_check_size(cpy, arg);
		if (arg->p_err == 1)
			break ;
		else
			cpy++;
	}
	ft_check_flag(cpy, arg);
	*format = cpy;
	if (arg->flag != '\0')
	{
		ft_check_precision(cpy, arg);
		ft_check_width(cpy, arg);
		ft_doublecheck(arg);
		(*format)++;
	}
}
