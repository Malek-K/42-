/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 15:23:11 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/28 12:32:23 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void		ft_arg_n_fd_errors(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putendl_fd("ERROR : Too Many Arguments.", 2);
		ft_putendl_fd("Usage : ./lem-in < [file].", 2);
		exit(1);
	}
	if (read(0, av[1], 0) == -1)
	{
		ft_putendl_fd("ERROR : Fail to read file.", 2);
		ft_putendl_fd("Usage : ./lem-in < [file].", 2);
		exit(1);
	}
}

int				main(int ac, char **av)
{
	t_check		*list;
	t_info		*data;

	ft_arg_n_fd_errors(ac, av);
	if (!(list = (t_check*)ft_memalloc(sizeof(t_check))))
		return (-1);
	if (!(data = (t_info*)ft_memalloc(sizeof(t_info))))
	{
		ft_memdel((void**)&list);
		return (-1);
	}
	ft_parse(0, list, data);
	delete_list(&list);
	delete_info(&data);
	return (0);
}
