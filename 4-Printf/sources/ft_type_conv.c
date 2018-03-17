/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_conv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 15:18:49 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 16:13:16 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"

t_funk g_flagtab[] =
{
	{&ft_flag_s, 's'},
	{&ft_flag_cap_s, 'S'},
	{&ft_flag_p, 'p'},
	{&ft_flag_d, 'd'},
	{&ft_flag_cap_d, 'D'},
	{&ft_flag_i, 'i'},
	{&ft_flag_o, 'o'},
	{&ft_flag_cap_o, 'O'},
	{&ft_flag_u, 'u'},
	{&ft_flag_cap_u, 'U'},
	{&ft_flag_x, 'x'},
	{&ft_flag_cap_x, 'X'},
	{&ft_flag_c, 'c'},
	{&ft_flag_cap_c, 'C'},
	{&ft_flag_b, 'b'},
	{&ft_flag_n, 'n'},
	{&ft_flag_f, 'f'},
	{&ft_flag_f, 'F'},
	{NULL, -1}
};

char		*ft_type_conv(va_list *ap, t_data *arg)
{
	char	*str;
	int		i;

	str = NULL;
	i = 0;
	if (arg->f_field == 1)
	{
		while (g_flagtab[i].flag != -1)
		{
			if (g_flagtab[i].flag == arg->flag)
				str = g_flagtab[i].ptrfunc(ap, arg);
			i++;
		}
	}
	else
		*str = arg->flag;
	return (str);
}
