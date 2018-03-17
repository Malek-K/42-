/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/23 18:27:44 by mkamel            #+#    #+#             */
/*   Updated: 2018/01/08 14:53:19 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int        main(int argc, char **argv)
{
	int        fd;
	char    *line;
	int        i;

	line = NULL;
	i = 2;
	fd = open(argv[1], O_RDONLY);
	printf("fd = %d\n", fd);
	if (argc == 2)
	{
		printf("enter the main\n");
		while (i != 0)
		{
			if (line)
				ft_strdel(&line);
			i = get_next_line(fd, &line);
			printf("retour de get_next_line = %d\n", i);
			printf("line = %s\n\n", line);
			sleep(3);
			if (i == -1)
				return (0);
		}
	}
	sleep (5);
	return (0);
}
