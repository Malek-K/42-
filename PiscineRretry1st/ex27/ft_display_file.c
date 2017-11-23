/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 19:40:04 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/08 21:04:46 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/uio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		fd;
	int		nbread;
	char	buffer[10000];

	fd = open(argv[1], O_RDONLY);
	nbread = read(fd, buffer, sizeof(buffer));
	if (argc == 1)
		ft_putstr("File name missing.\n");
	else if (argc > 2)
		ft_putstr("Too many arguments.\n");
	else if (argc == 2)
	{
		while (nbread > 0)
		{
			write(1, buffer, nbread);
			nbread = read(fd, buffer, sizeof(buffer));
		}
	}
	close(fd);
	return (0);
}
