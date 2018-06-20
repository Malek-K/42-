/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:57:39 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 19:52:21 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	SIGNALS THE ERROR IF OVER THE MIN/MAX LIMIT OF AN INT
**	IF NO ERROR, INCREMENT T, THE NUMBER OF THE ARGUMENTS OF THE FUTURE THE LIST
*/

static int	ft_deal_int(char *s, size_t *k, int *t)
{
	if (ft_atoi(s + *k) < -2147483648 || ft_atoi(s + *k) > 2147483647)
		return (-1);
	if (s[*k] && ft_strchr("-0123456789", s[*k]) != NULL)
		*t = *t + 1;
	*k = *k + 1;
	return (0);
}

/*
**	CHECK IF THE NUMBER ARGUMENT IS AN INT OR CONTAINS C/V/Q/Z.
**	RETURN -1 IF ERROR
**	ERROR CASES :	- IF MORE THAN 10 CHARACTERS
**					- IF ATOI IS OVER THE MIN/MAX LIMIT OF THE INT
*/

static int	ft_isnotint(int i, char **argv, int *t, int x)
{
	size_t	k;

	k = 0;
	while (k < ft_strlen(argv[i]))
	{
		x = 0;
		while (argv[i][k] && ft_strchr(" \n \t \v \f \r", argv[i][k]) != NULL)
			k++;
		argv[i][k] == '+' ? k++ : 0;
		if (argv[i][k] == '-' && ft_strchr("cvqz", argv[i][k + 1]) != NULL)
			k += 2;
		else if (ft_deal_int(argv[i], &k, t) == -1)
			return (-1);
		while (argv[i][k] && argv[i][k] == '0' && \
				ft_strchr("0123456789", argv[i][k + 1]) != NULL)
			k++;
		while (argv[i][k] && ft_strchr("0123456789", argv[i][k++]) != NULL)
			if (++x > 10)
				return (-1);
	}
	return (0);
}

/*
**	CHECK, ONCE THE TAB OF INT VALUES IS CREATED, IF THERE ARE NO DOUBLOONS
**	BY COMPARING EACH CHARACTER TO THE  REST OF THE TAB, BEGINNIG WITH THE FIRST
*/

static int	ft_checkdouble(int *tab, int t)
{
	int		j;
	int		k;

	j = 0;
	while (j < t - 1)
	{
		k = j + 1;
		while (k < t)
		{
			if (tab[j] == tab[k])
				return (-1);
			k++;
		}
		j++;
	}
	return (0);
}

/*
**	FILLS THE TAB, ALREADY ALLOCATED, WITH THE VALUES INSIDE EACH ARGUMENT
**	IF '-' AND OPTION C/V AFTER, JUMPS IT RO REACH THE NEXT NUMBER
**	THEN CHECKS IF DOUBLOONS ARE PRESENT OR NOT
*/

static int	ft_isdouble_tab(int *tab, int t, int argc, char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] && k < t)
		{
			while (argv[i][j] && ft_strchr(" \n\t\v\f\r", argv[i][j]) != NULL)
				j++;
			argv[i][j] == '+' ? j++ : 0;
			argv[i][j] == '-' && ft_strchr("cvqz", argv[i][j + 1]) != NULL ? \
						j += 2 : 0;
			if (ft_strchr("-0123456789", argv[i][j]) != NULL && argv[i][j])
				tab[k++] = ft_atoi(argv[i] + j++);
			while (argv[i][j] && ft_strchr("-0123456789", argv[i][j]) != NULL)
				j++;
		}
		i++;
	}
	return (ft_checkdouble(tab, t) == -1) ? -1 : 0;
}

/*
**	STEPS OF THE ERROR CHECK
**	1 - THE ARGUMENT IS EITHER A NUMBER OR OPTION INFO (- C/V/Q/Z)
**	2 - THE ARGUMENT IS AN INTEGER
**	3 - THERE IS AT LEAST 1 NUMBER IN THE ARGUMENTS
**	4 - ALLOCATES AND CREATE A TAB FROM ALL THE VALUES, CHECK IF DOUBLOONS
**	5 - MALLOC THE TWO LISTS AND PUT ALL THOSE VALUES IN LIST A
**	6 - FREE THE TAB
*/

int			ft_check_errors(int argc, char **argv, t_dllist **a, t_dllist **b)
{
	int		i;
	int		t;
	int		*tab;

	i = 1;
	t = 0;
	while (i < argc)
	{
		if (ft_isnb(i, argv) == -1 || ft_isnotint(i, argv, &t, 0) == -1)
			return (-1);
		i++;
	}
	tab = malloc(sizeof(*tab) * t);
	if (ft_isdouble_tab(tab, t, argc, argv) == -1)
	{
		free(tab);
		return (-1);
	}
	ft_putarg_inlst(a, b, t, tab);
	free(tab);
	return (0);
}
