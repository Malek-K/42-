/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:45:21 by alima             #+#    #+#             */
/*   Updated: 2017/11/29 14:59:56 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*ft_read(char *files, char *buf)
{
	int	size;
	int	fd;

	if (!files)
		return ("error\n");
	if ((fd = open(files, O_RDONLY)) != -1)
	{
		size = read(fd, buf, BUF_SIZE);
		buf[size] = '\0';
	}
	if (close(fd) != -1)
		return (buf);
	else
		return ("error\n");
}
