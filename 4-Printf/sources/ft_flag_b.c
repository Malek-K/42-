/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/12 21:46:08 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/03 23:02:22 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_i_deal(int *i, t_data *arg, char *ret)
{
	*i -= 1;
	while (*i >= 0)
		ret[(*i)--] = '0';
	*i = arg->length_f % 8;
}

static char		*ft_spaces_in_nbr(char *nb, t_data *arg, size_t l)
{
	size_t		t;
	int			i;
	char		*ret;

	i = (l > 8) ? 8 - (l % 8) : 8 - l;
	t = (l % 8 == 0) ? l + (l / 8) - 1 : l + (l / 8) + (8 - (l % 8));
	ret = ft_strnew(t);
	arg->length_f = t;
	ft_i_deal(&i, arg, ret);
	while (l-- && t--)
	{
		if ((t - i) % 8 == 0 && (t - 1 + (arg->length_f % 8)) != arg->length_f)
		{
			ret[(t)] = nb[l];
			if ((t - 1) > 0)
				ret[(t-- - 1)] = ' ';
			i--;
		}
		else
			ret[(t)] = nb[l];
	}
	free(nb);
	free(ret);
	return (ret);
}

char			*ft_flag_b(va_list *ap, t_data *arg)
{
	uintmax_t	nb;
	char		*nbr;
	size_t		lenstr;

	nb = va_arg(*ap, uintmax_t);
	nbr = ft_strdup(ft_utoa_base(nb, 2));
	lenstr = ft_strlen(nbr);
	nbr = ft_spaces_in_nbr(nbr, arg, lenstr);
	return (nbr);
}
