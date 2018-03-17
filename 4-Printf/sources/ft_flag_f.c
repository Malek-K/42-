/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_f.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 13:39:43 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 21:03:06 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static float		power(intmax_t x, intmax_t n, t_data *arg)
{
	if (n == 0 && arg->p_field == 0)
	{
		n = 6;
		arg->precision = 6;
	}
	if (n == 0 && arg->p_field == 1)
		return (0);
	else
	{
		while (n--)
			x *= 10;
	}
	return (x);
}

static char			*ft_dot_in_nbr(char *nb, t_data *arg, size_t l)
{
	char			*ret;

	if (*nb != '0')
	{
		ret = ft_strnew(l);
		while (arg->precision-- && l--)
			ret[(l)] = nb[l - 1];
		ret[--l] = '.';
		while (l--)
			ret[l] = nb[l];
	}
	else
	{
		l = (arg->precision + 1 < l) ? arg->precision + 1 : l;
		ret = ft_strnew(l + 1);
		while (arg->precision-- && l--)
			ret[(l + 1)] = (*nb != '0') ? nb[l - 1] : '0';
		ret[--l + 1] = '.';
		ret[0] = '0';
	}
	arg->length_f = l;
	free(nb);
	free(ret);
	return (ret);
}

static void			ft_normal_deal(long double nb, t_data *arg, char **nbr)
{
	long double		bis;
	intmax_t		ten_pow;
	intmax_t		total;

	ten_pow = power(1, arg->precision, arg);
	if (arg->precision == 0 && arg->p_field == 1)
		ten_pow = 1;
	bis = (nb >= 0) ? nb * ten_pow + 0.5 : nb * ten_pow - 0.5;
	total = bis;
	bis = total;
	nb = bis / ten_pow;
	total = (ten_pow != 0) ? (nb * ten_pow) : (intmax_t)nb;
	total += (total != 0 && ten_pow != 0 && total % 9 == 0) ? 1 : 0;
	if (total != 0)
		*nbr = ft_strdup(ft_itoa_base(total, 10));
	else if (total == 0)
		*nbr = ft_strdup("0000000");
	if (ten_pow != 0)
		*nbr = ft_dot_in_nbr(*nbr, arg, ft_strlen(*nbr) + 1);
	arg->precision = 0;
	arg->p_field = 0;
	arg->length_f = ft_strlen(*nbr);
}

char				*ft_flag_f(va_list *ap, t_data *arg)
{
	long double		nb;
	char			*nbr;

	nb = 0.0;
	if (arg->dbl == 0)
		nb = va_arg(*ap, double);
	else if (arg->dbl == 1)
		nb = va_arg(*ap, long double);
	if (nb == 10.0 / 0.0 || nb != nb)
	{
		arg->p_field = 0;
		arg->precision = 0;
		arg->w_field = 1;
		arg->width = (arg->width < 3) ? 3 : arg->width;
		if (nb == 10.0 / 0.0)
			return (arg->flag == 'f' ? "inf" : "INF");
		else
			return (arg->flag == 'f' ? "nan" : "NAN");
	}
	else
		ft_normal_deal(nb, arg, &nbr);
	return (nbr);
}
