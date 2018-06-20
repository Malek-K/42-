/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_length.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 17:18:28 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 15:20:39 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_init_len(t_data *arg, size_t *len, size_t *lenstr,\
		char *f_str)
{
	*lenstr = ft_strlen(f_str);
	arg->length_f += (!arg->p_field && (!arg->w_field || arg->width <= \
				ft_strlen(f_str)) && arg->plus && *f_str != '-') ? 1 : 0;
	if (arg->p_field && arg->w_field)
	{
		*len = (arg->precision >= arg->width) ? arg->precision : arg->width;
		*len = (*len > arg->length_f) ? *len : arg->length_f;
	}
	else if (arg->p_field && !arg->w_field)
		*len = (arg->precision > arg->length_f) ? \
			arg->precision : arg->length_f;
	else if (!arg->p_field && arg->w_field)
		*len = (arg->width > arg->length_f) ? arg->width : arg->length_f;
	else if (!arg->p_field && !arg->w_field)
		*len = arg->length_f;
	if (ft_strchr("sS", arg->flag) && arg->p_field && \
			arg->precision > *lenstr && !arg->w_field)
		*len = arg->length_f;
}

static void		ft_pnh(t_data *arg, size_t *len, size_t *lenstr, char *f_str)
{
	if (arg->precision >= arg->width)
	{
		*len += ((ft_strchr("oO", arg->flag) && arg->hash && \
					arg->precision <= *lenstr && *f_str != '0')) ? 1 : 0;
		*len += ((ft_strchr("xX", arg->flag) && arg->hash && \
					ft_strcmp(f_str, "0")) || \
				(ft_strchr("pb", arg->flag) && ft_strcmp(f_str, "0x"))) ? 2 : 0;
	}
	else if (arg->precision == arg->width - 1)
		arg->length_f += ((ft_strchr("xX", arg->flag) && \
					arg->hash && ft_strcmp(f_str, "0")) || \
				(ft_strchr("pb", arg->flag) && ft_strcmp(f_str, "0x"))) ? 1 : 0;
}

static void		ft_hash(t_data *arg, size_t *len, size_t *lenstr, char *f_str)
{
	if ((arg->hash && arg->p_field) || \
			(ft_strchr("pb", arg->flag) && arg->p_field))
		ft_pnh(arg, len, lenstr, f_str);
	else if (!arg->p_field && (!arg->w_field || arg->width <= ft_strlen(f_str))\
			&& arg->f_field)
	{
		*len += ((ft_strchr("oO", arg->flag) && arg->hash && \
					ft_strcmp(f_str, "0"))) ? 1 : 0;
		*len += ((ft_strchr("xX", arg->flag) && arg->hash && \
					ft_strcmp(f_str, "0")) || \
				(ft_strchr("pb", arg->flag) && ft_strcmp(f_str, "0x"))) ? 2 : 0;
	}
	else if (!arg->p_field && arg->width == (ft_strlen(f_str) + 1) && \
			arg->f_field)
	{
		*len += ((ft_strchr("xX", arg->flag) && arg->hash && \
					ft_strcmp(f_str, "0")) || \
				(ft_strchr("pb", arg->flag) && ft_strcmp(f_str, "0x"))) ? 1 : 0;
	}
}

int				ft_length(t_data *arg, char *f_str)
{
	size_t		len;
	size_t		lenstr;

	ft_init_len(arg, &len, &lenstr, f_str);
	ft_hash(arg, &len, &lenstr, f_str);
	arg->length_f += (ft_strchr("pb", arg->flag) && \
			ft_strcmp(f_str, "0x")) ? 2 : 0;
	if (ft_strchr("dDifF", arg->flag) && arg->f_field)
	{
		if (arg->p_field && arg->precision >= arg->width && \
				arg->precision >= ft_strlen(f_str))
			len += (*f_str == '-' || arg->plus || arg->space) ? 1 : 0;
		else if (arg->width == arg->length_f && arg->precision < arg->width)
			len += ((*f_str != '-' && arg->plus) || arg->space) ? 1 : 0;
		else if (!arg->plus && arg->space && arg->width <= ft_strlen(f_str))
			len += (*f_str != '-') ? 1 : 0;
	}
	return (len);
}
