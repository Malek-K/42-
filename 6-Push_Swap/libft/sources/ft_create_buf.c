/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_buf.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 15:54:39 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 16:18:28 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_rev_spaces(char **f_str, t_data *arg, int neg, size_t *i)
{
	size_t		len;
	size_t		l;
	int			bonus;
	size_t		max;

	max = 0;
	l = (ft_strchr("cC", arg->flag) && **f_str == '\0') ? 1 : ft_strlen(*f_str);
	len = arg->length_f + arg->length_bf - 1;
	bonus = 0;
	bonus += ((ft_strchr("oO", arg->flag) && arg->hash && **f_str != '0') || \
		(arg->plus && !neg)) ? 1 : 0;
	bonus += ((ft_strchr("xX", arg->flag) && arg->hash && \
		ft_strcmp(*f_str, "0")) || (ft_strchr("pb", arg->flag) && \
		ft_strcmp(*f_str, "0x"))) ? 2 : 0;
	if (ft_strchr("dDi", arg->flag) && \
			(arg->p_field && arg->precision >= arg->width))
		bonus += (**f_str == '-' || arg->plus || arg->space) ? 1 : 0;
	else if (ft_strchr("dDi", arg->flag) && \
			!arg->plus && arg->space && arg->width <= ft_strlen(*f_str))
		bonus += (**f_str != '-') ? 1 : 0;
	max = (l >= arg->precision) ? l : arg->precision;
	while (*i < (arg->length_f - bonus - max))
		arg->buf[len - (*i)++] = ' ';
}

static void		ft_do_reverse(char **f_str, t_data *arg, int neg)
{
	size_t		len;
	size_t		l;
	size_t		i;
	size_t		p;

	p = 0;
	l = (ft_strchr("cC", arg->flag) && **f_str == '\0') ? 1 : ft_strlen(*f_str);
	len = arg->length_f + arg->length_bf - 1;
	i = 0;
	ft_rev_spaces(f_str, arg, neg, &i);
	while (l--)
		arg->buf[len - i++] = (*(*f_str + l));
	l = (ft_strchr("cC", arg->flag) && **f_str == '\0' && arg->f_field) ? \
			1 : ft_strlen(*f_str);
	while (ft_strchr("pdDioOuUxXbfF", arg->flag) && (p++ + l < arg->precision))
		arg->buf[len - i++] = '0';
	i -= (neg == 1) ? 1 : 0;
	ft_pwdeal(f_str, arg, neg, &i);
	if (arg->space == 1 && arg->width > l)
		arg->buf[len - i + 1] = ' ';
	if (arg->space == 1 && arg->width <= l)
		arg->buf[len - i] = ' ';
}

static void		ft_do(char **f_str, t_data *arg, int neg)
{
	size_t		len;
	size_t		lenstr;
	size_t		i;

	lenstr = (ft_strchr("cC", arg->flag) && **f_str == '\0' && arg->f_field) ? \
		1 : ft_strlen(*f_str);
	len = arg->length_f + arg->length_bf - 1;
	i = 0;
	while (lenstr--)
		arg->buf[len - i++] = (*(*f_str + lenstr));
	i -= (neg == 1) ? 1 : 0;
	ft_pwdeal(f_str, arg, neg, &i);
	lenstr = (ft_strchr("cC", arg->flag) && **f_str == '\0') ? \
			1 : ft_strlen(*f_str);
	if (arg->space == 1 && arg->width > lenstr)
		arg->buf[len - i + 1] = ' ';
	else if (arg->space == 1 && arg->width <= lenstr)
		arg->buf[len - i] = ' ';
}

void			ft_create_buf(char **f_str, t_data *arg)
{
	int			neg;

	if ((ft_strchr("dDifF", arg->flag) && **f_str == '-'))
		arg->space = 0;
	neg = (**f_str == '-' && ft_strchr("dDifF", arg->flag)) ? 1 : 0;
	if (arg->minus == 0)
		ft_do(f_str, arg, neg);
	else
		ft_do_reverse(f_str, arg, neg);
}
