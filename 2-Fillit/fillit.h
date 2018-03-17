/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 13:10:24 by alima             #+#    #+#             */
/*   Updated: 2017/12/11 18:11:18 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef H_FILLIT_H
# define H_FILLIT_H
# define BUF_SIZE 551
# include <unistd.h>
# include <fcntl.h>
# include "libft/libft.h"

char				*ft_read(char *files, char *buf);
int					ft_check(char *buf);
int					ft_checkform(char **buf);

typedef struct		s_lst
{
	char			letter;
	char			*str;
	int				x[4];
	int				y[4];
	struct s_lst	*next;
}					t_lst;

t_lst				*ft_range(char *buf);
char				*ft_upnleft(char *str);
char				**ft_retry(char **grid, t_lst *list, int size);
int					ft_gridsize(t_lst *list);
char				**ft_gridmaker(char **grid, int size);
char				**ft_backtracking(t_lst *list, int size, char **grid);
int					ft_check_nb_tetri(char *str);
#endif
