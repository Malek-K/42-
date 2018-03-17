/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_width.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/02 16:54:06 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 22:18:34 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

static void		ft_search_width(char *end, t_data *arg)
{
	if (*(end + 1) == '$')
	{
		while (ft_isdigit(*end) == 1)
			end--;
		while ((ft_isdigit(*end) == 0 && *end != '%') || \
				(*end == '*' && *(end - 1) != '.'))
			end--;
	}
	while ((*end && *end != '%') || (*end == '*' && *(end - 1) != '.'))
	{
		while (ft_isdigit(*end) == 1)
			end--;
		if (*end != '.' && ft_atoi(end + 1) != 0)
		{
			arg->width = ft_atoi(end + 1);
			break ;
		}
		else
		{
			if (*end == '*')
				break ;
			while (ft_isdigit(*end) == 0 && *end != '%' && *end != '*')
				end--;
		}
	}
}

void			ft_check_width(char *cpy, t_data *arg)
{
	char		*end;
	int			w;

	end = cpy - 1;
	while ((ft_isdigit(*end) == 0 && *end != '%') || \
			(*end == '*' && *(end - 1) != '.'))
		end--;
	if (ft_isdigit(*end) == 1 && *(end + 1) != '*')
		ft_search_width(end, arg);
	w = arg->width;
	if (!arg->minus)
		arg->minus = (w < 0 && arg->minus == 0) ? 1 : 0;
	arg->width = (w < 0) ? -arg->width : arg->width;
	arg->w_field = (arg->width > 0 || arg->w_field != 0) ? 1 : 0;
}
