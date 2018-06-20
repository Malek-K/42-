/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_errors.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 18:57:39 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 20:01:40 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"
#define MIN -2147483648
#define MAX 2147483647

/*
**	CHECK IF EACH CHARACTER OF THE ARGUMENT IS A PROPER NUMBER, OR A +/-
**		IF +/- : CHECK IF WHAT IS BEFORE IS A WHITESPACE
**				AND IF WHAT IS AFTER IS A NUMBER
**		IF NO NUMBER IN THE ARGUMENT, THE COUNTER X == 0, RETURN -1
*/

static int	ft_isnb(int i, char **argv)
{
	int		j;
	int		x;

	j = 0;
	x = 0;
	while (argv[i][j] && \
			ft_strchr("\n\t\v\f\r 0123456789 +-", argv[i][j]) != NULL)
	{
		(ft_strchr("0123456789", argv[i][j]) != NULL) ? x++ : 0;
		if (ft_strchr("+-", *(argv[i] + j)) != NULL &&
			ft_strchr(" \n\t\v\f\r\0", *(argv[i] + j - 1)) == NULL)
			return (-1);
		if (ft_strchr("-+", *(argv[i] + j)) != NULL && \
				ft_strchr("0123456789", *(argv[i] + j + 1)) == NULL)
			return (-1);
		if (ft_strchr("+-", *(argv[i] + j)) != NULL && !*(argv[i] + j + 1))
			return (-1);
		j++;
	}
	if (argv[i][j] != '\0' || x == 0)
		return (-1);
	return (0);
}

/*
**	CHECK IF THE NUMBER ARGUMENT IS AN INT AND RETURN -1 IF ERROR
**	ERROR CASES :	- IF MORE THAN 10 CHARACTERS
**					- IF ATOI IS OVER THE MIN/MAX LIMIT OF THE INT
**	IF NO ERROR, INCREMENT T, THE NUMBER OF  ELEMENTS OF THE FUTURE THE LIST
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
		if (ft_atoi(argv[i] + k) < MIN || ft_atoi(argv[i] + k) > MAX)
			return (-1);
		if (argv[i][k] && ft_strchr("-0123456789", argv[i][k++]) != NULL)
			*t = *t + 1;
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
**	CHECK IF THE ARGUMENTS ARE CORRECT (ONLY NUMBERS, AND THEY ARE INT)
**	THEN ALLOCATES A TAB TO FILL IN WITH THE VALUES AND CHECK IF DOUBLOONS
**	FINALLY PUT EVERY VALUES IN THE LIST A AND FREE TAB
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
