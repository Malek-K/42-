/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/02 15:03:40 by mkamel            #+#    #+#             */
/*   Updated: 2018/01/16 11:45:23 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 11
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_line
{
	int				fd;
	char			*tmp;
	struct s_line	*next;
}					t_line;
int					get_next_line(const int fd, char **line);

#endif
