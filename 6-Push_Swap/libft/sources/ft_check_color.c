/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_color.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 15:26:22 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/07 23:33:13 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/printf.h"
#include <stdio.h>

#define RED   "\033[31m"
#define GRN   "\033[32m"
#define YEL   "\033[33m"
#define BLU   "\033[34m"
#define MAG   "\033[35m"
#define CYN   "\033[36m"
#define WHT   "\033[37m"
#define EOC "\033[0m"
#define BAL "\033[1m"
#define UND "\033[4m"

static int		ft__is_color(char *col)
{
	if (ft_strcmp(col, "red") == 0 || ft_strcmp(col, "gre") == 0 || \
		ft_strcmp(col, "yel") == 0 || ft_strcmp(col, "blu") == 0 || \
		ft_strcmp(col, "mag") == 0 || ft_strcmp(col, "cya") == 0 || \
		ft_strcmp(col, "whi") == 0 || ft_strcmp(col, "eoc") == 0 || \
		ft_strcmp(col, "bal") == 0 || ft_strcmp(col, "und") == 0)
		return (1);
	else
		return (0);
}

static void		ft_life_in_color(char *col)
{
	if (ft_strcmp(col, "red") == 0)
		write(1, RED, 5);
	if (ft_strcmp(col, "gre") == 0)
		write(1, GRN, 5);
	if (ft_strcmp(col, "yel") == 0)
		write(1, YEL, 5);
	if (ft_strcmp(col, "blu") == 0)
		write(1, BLU, 5);
	if (ft_strcmp(col, "mag") == 0)
		write(1, MAG, 5);
	if (ft_strcmp(col, "cya") == 0)
		write(1, CYN, 5);
	if (ft_strcmp(col, "whi") == 0)
		write(1, WHT, 5);
	if (ft_strcmp(col, "eoc") == 0)
		write(1, EOC, 4);
	if (ft_strcmp(col, "bal") == 0)
		write(1, BAL, 4);
	if (ft_strcmp(col, "und") == 0)
		write(1, UND, 4);
}

void			ft_check_color(const char **format, t_data *arg)
{
	char		*col;

	col = ft_strsub(*format, 1, 3);
	if (ft__is_color(col) == 1)
	{
		if (*arg->start_ptr != '{' && arg->length_bf != 1)
			ft_putnstr(arg->start_ptr, arg->length_bf);
		ft_life_in_color(col);
		*format = (*format) + 5;
		arg->start_ptr = (char*)*format;
		arg->length_bf = 0;
	}
	free(col);
}
