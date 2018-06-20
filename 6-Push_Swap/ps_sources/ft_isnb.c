/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnb.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/03 16:42:18 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 19:15:56 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	ERROR CASES :
**	IF +/- : CHECK IF WHAT IS BEFORE IS A WHITESPACE
**				AND IF WHAT IS AFTER IS A NUMBER (OR C/V/Q/Z FOR A '-')
**	IF - WITH A C/V/Q/Z AFTER : CHECK IF WHAT IS AFTER IS A WHITESPACE
**	IF A C/V/Q/Z : CHECK IF WHAT IS BEFORE IS A '-'
*/

int			ft_error_cases(int i, int j, char **argv)
{
	if (ft_strchr("+-", *(argv[i] + j)) != NULL &&
			ft_strchr(" \n\t\v\f\r\0", *(argv[i] + j - 1)) == NULL)
		return (-1);
	if (ft_strchr("+", *(argv[i] + j)) != NULL && \
			ft_strchr("0123456789", *(argv[i] + j + 1)) == NULL)
		return (-1);
	if (ft_strchr("-", *(argv[i] + j)) != NULL && \
			ft_strchr("0123456789cvqz", *(argv[i] + j + 1)) == NULL)
		return (-1);
	if (ft_strchr("-", *(argv[i] + j)) != NULL && \
			ft_strchr("cvqz", *(argv[i] + j + 1)) != NULL && \
			ft_strchr(" \n\t\v\f\r\0", *(argv[i] + j + 2)) == NULL)
		return (-1);
	if (ft_strchr("cvqz", *(argv[i] + j)) != NULL && \
			(ft_strchr("-", *(argv[i] + j - 1)) == NULL || j == 0))
		return (-1);
	if (ft_strchr("+-", *(argv[i] + j)) != NULL && !*(argv[i] + j + 1))
		return (-1);
	return (0);
}

/*
**	CHECK IF EACH CHARACTER OF THE ARGUMENT IS A PROPER NUMBER, OR A +/-/C/V/Q/Z
*/

int			ft_isnb(int i, char **argv)
{
	int		j;
	int		k;
	int		l;

	j = 0;
	k = 0;
	l = 0;
	while (argv[i][j] && \
			ft_strchr("\n\t\v\f\r 0123456789 +- cvqz", argv[i][j]) != NULL)
	{
		(ft_strchr("0123456789", argv[i][j]) != NULL) ? k++ : 0;
		(ft_strchr("cvqz", argv[i][j]) != NULL) ? l++ : 0;
		if (ft_error_cases(i, j, argv) == -1)
			return (-1);
		j++;
	}
	if (argv[i][j] != '\0' || (k == 0 && l == 0))
		return (-1);
	return (0);
}
