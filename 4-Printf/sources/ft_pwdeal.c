/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwdeal.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/13 18:54:42 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/05 21:49:50 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void	ft_do_hash(t_data *arg, size_t len, size_t *i, char **f_str)
{
	if ((arg->flag == 'o' || arg->flag == 'O') && arg->buf[len - *i + 1] != '0')
	{
		arg->buf[len - *i] = '0';
		*i += 1;
	}
	if ((arg->flag == 'x' || arg->flag == 'X') && **f_str && **f_str != '0')
	{
		arg->buf[len - *i] = (arg->flag == 'x') ? 'x' : 'X';
		arg->buf[len - *i - 1] = '0';
		*i += 2;
	}
	if (arg->flag == 'b' || arg->flag == 'p')
	{
		arg->buf[len - *i] = (arg->flag == 'b') ? 'b' : 'x';
		arg->buf[len - *i - 1] = '0';
		*i += 2;
	}
	arg->hash = 0;
}

static void	ft_do_final_hash(t_data *arg, size_t len, size_t *i, char **f_str)
{
	size_t	lenstr;

	lenstr = ft_strlen(*f_str);
	if ((arg->flag == 'o' || arg->flag == 'O') && arg->buf[len - *i + 1] != '0')
	{
		arg->buf[len - *i] = '0';
	}
	if ((arg->flag == 'x' || arg->flag == 'X') && **f_str && **f_str != '0')
	{
		arg->buf[len - *i + 2] = (arg->flag == 'x') ? 'x' : 'X';
	}
	if ((arg->flag == 'b' || arg->flag == 'p') && arg->width > lenstr)
	{
		arg->buf[len - *i + 2] = (arg->flag == 'b') ? 'b' : 'x';
	}
}

static void	ft_deal_sign(t_data *arg, int neg, size_t *i, size_t len)
{
	if (neg)
	{
		arg->buf[len - *i] = '-';
		*i += 1;
	}
	else if (arg->plus)
	{
		arg->buf[len - *i] = '+';
		*i += 1;
	}
}

static void	ft_final_deal(char **f_str, t_data *arg, int neg, size_t *i)
{
	size_t	len;
	size_t	lenstr;
	char	c;

	lenstr = (ft_strchr("cC", arg->flag) && **f_str == '\0' && arg->f_field) ? \
			1 : ft_strlen(*f_str);
	len = arg->length_f + arg->length_bf - 1;
	c = (arg->zero) ? '0' : ' ';
	if (neg && !arg->p_field && c == '0' && arg->width > lenstr)
		arg->buf[len - *i + 1] = '-';
	else if (!neg && !arg->p_field && arg->plus && c == '0' && \
			arg->width > lenstr)
		arg->buf[len - *i + 1] = '+';
	else if (!neg && !arg->p_field && arg->plus && arg->w_field && \
			arg->width <= lenstr)
		arg->buf[len - *i] = '+';
}

void		ft_pwdeal(char **f_str, t_data *arg, int neg, size_t *i)
{
	size_t	len;
	size_t	lenstr;
	char	c;

	lenstr = (ft_strchr("cC", arg->flag) && **f_str == '\0' && arg->f_field) ? \
			1 : ft_strlen(*f_str);
	len = arg->length_f + arg->length_bf - 1;
	c = (arg->zero) ? '0' : ' ';
	while (ft_strchr("pdDioOuUxXfF", arg->flag) && \
			*i < arg->precision && arg->p_field)
		arg->buf[len - (*i)++] = '0';
	if (arg->p_field || c == ' ')
		ft_deal_sign(arg, neg, i, len);
	if ((arg->hash == 1 || (ft_strchr("pb", arg->flag))) && \
			(arg->p_field || c == ' '))
		ft_do_hash(arg, len, i, f_str);
	else if (ft_strchr("pb", arg->flag) && (arg->width < lenstr) \
			&& !arg->p_field)
		ft_do_hash(arg, len, i, f_str);
	while (*i < arg->width && !arg->minus)
		arg->buf[len - (*i)++] = c;
	if (arg->hash == 1 && !arg->p_field)
		ft_do_final_hash(arg, len, i, f_str);
	ft_final_deal(f_str, arg, neg, i);
}
