/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 14:15:06 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 23:36:27 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_dealstrings(t_data *arg)
{
	if (arg->precision < ft_strlen(arg->f_str))
	{
		while ((arg->flag == 'S' || arg->size == 3) && \
				(*(arg->f_str + arg->precision) & 0xC0) == 0x80)
			arg->precision -= 1;
		ft_strclr(arg->f_str + arg->precision);
	}
	else
		arg->precision = 0;
	arg->length_f = ft_strlen(arg->f_str);
}

static void		ft_printf_build(va_list *ap, t_data *arg, intmax_t *octet)
{
	arg->octet = *octet + arg->length_bf;
	if (arg->f_field == 1)
		arg->f_str = ft_strdup(ft_type_conv(ap, arg));
	else if (!arg->f_field)
	{
		arg->f_str = ft_strdup(ft_wchar_to_str((wchar_t)arg->flag));
		arg->length_f = ft_strlen(arg->f_str);
	}
	if ((arg->flag == 's' || arg->flag == 'S') && arg->p_field)
		ft_dealstrings(arg);
	arg->length_f = (arg->flag != 'n') ? ft_length(arg, arg->f_str) : 0;
	arg->buf = ft_strnew(arg->length_bf + arg->length_f);
	if (arg->length_bf)
		arg->buf = ft_strncpy(arg->buf, arg->start_ptr, arg->length_bf);
	if (arg->flag != 'n')
		ft_create_buf(&arg->f_str, arg);
	if (ft_strchr("cC", arg->flag) && *arg->f_str == '\0' && arg->f_field)
		ft_putnstr(arg->buf, arg->length_bf + arg->length_f);
	else
		ft_putstr(arg->buf);
	*octet += (ft_strchr("cC", arg->flag) && *arg->f_str == '\0') ? \
			arg->length_bf + arg->length_f : ft_strlen(arg->buf);
	ft_strdel(&arg->buf);
	ft_strdel(&arg->f_str);
}

static void		ft_search_percent(const char **format, t_data *arg, \
		intmax_t *octet)
{
	arg->start_ptr = (char*)*format;
	while (**format && **format != '%')
	{
		if (**format == '{' && *(*format + 4) && *(*format + 4) == '}')
			ft_check_color(format, arg);
		if (**format == '%')
			break ;
		(*format)++;
		arg->length_bf++;
	}
	if (**format == '\0')
	{
		ft_putstr(arg->start_ptr);
		*octet += arg->length_bf;
	}
}

static int		ft_parse(const char *format, va_list *ap, va_list *bp)
{
	t_data		arg;
	intmax_t	octet;

	ft_bzero(&arg, sizeof(arg));
	octet = 0;
	while (*format)
	{
		if (*format == '%')
		{
			ft_checks(ap, bp, &format, &arg);
			ft_printf_build(ap, &arg, &octet);
			ft_bzero(&arg, sizeof(arg));
		}
		else
			ft_search_percent(&format, &arg, &octet);
	}
	return (octet);
}

int				ft_printf(const char *format, ...)
{
	intmax_t	octet;
	va_list		ap;
	va_list		bp;

	va_start(ap, format);
	va_copy(bp, ap);
	octet = ft_parse(format, &ap, &bp);
	va_end(ap);
	return (octet);
}
