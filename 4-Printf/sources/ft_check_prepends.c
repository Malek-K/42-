/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_prepends.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 14:40:21 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 21:56:33 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_dealpos(va_list *ap, va_list *bp, char *cpy, t_data *arg)
{
	char		*str;
	long int	nbr;

	str = cpy - 1;
	while (ft_isdigit(*str))
		str--;
	if (*str == '.')
		arg->p_err = 1;
	else
	{
		nbr = ft_atoi(str + 1) - 1;
		va_copy(*ap, *bp);
		while (nbr--)
			va_arg(*ap, void*);
	}
}

static void		ft_dealstar(va_list *ap, char *cpy, t_data *arg)
{
	if (*(cpy - 1) == '.')
	{
		arg->precision = va_arg(*ap, int);
		if ((intmax_t)arg->precision < 0)
		{
			arg->precision = 0;
			arg->p_field = 0;
		}
		else
			arg->p_field = 1;
	}
	else
	{
		arg->width = va_arg(*ap, intmax_t);
		arg->minus = ((int)arg->width < 0) ? 1 : arg->minus;
		arg->w_field = 1;
	}
}

void			ft_check_prepends(va_list *ap, va_list *bp, \
		char *cpy, t_data *arg)
{
	if (!arg->hash && *cpy == '#')
		arg->hash = 1;
	if (!arg->zero && *cpy == '0' && ft_isdigit(*(cpy - 1)) == 0)
		arg->zero = 1;
	if (!arg->minus && *cpy == '-')
		arg->minus = 1;
	if (!arg->plus && *cpy == '+')
		arg->plus = 1;
	if (!arg->space && *cpy == ' ')
		arg->space = 1;
	if (*cpy == '*')
		ft_dealstar(ap, cpy, arg);
	if (*cpy == '$')
		ft_dealpos(ap, bp, cpy, arg);
}
