/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dhuber <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/30 14:52:53 by dhuber            #+#    #+#             */
/*   Updated: 2018/06/29 13:54:49 by dhuber           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								INCLUDES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

# include "../ft_printf/includes/ft_printf.h"

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								STRUCTURES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

typedef struct		s_path
{
	struct s_room	*room;
	struct s_path	*next;
}					t_path;

typedef struct		s_check
{
	char			*line;
	struct s_check	*next;
}					t_check;

typedef struct		s_link
{
	int				num;
	char			pad[4];
	struct s_room	*room;
	struct s_link	*next;
}					t_link;

typedef struct		s_room
{
	int				x;
	int				y;
	int				color;
	int				dist;
	int				used;
	int				num;
	int				link;
	char			pad[4];
	char			*name;
	struct s_room	*door;
	struct s_room	*exit;
	t_link			*links;
}					t_room;

typedef struct		s_info
{
	int				ant;
	int				i_start;
	int				i_end;
	char			pad[4];
	size_t			nb_room;
	size_t			used_room;
	t_room			**room;
}					t_info;

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								PROTOTYPES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

int					main(int ac, char **av);
void				print_info(t_info *data);
void				print_list(t_check *list);
void				print_info(t_info *datas);
void				ft_parse(int fd, t_check *list, t_info *datas);
int					ft_check_list(t_check *list, t_info *datas, size_t i, \
		size_t nb);
size_t				ft_check_pipes(t_check *list, t_info *datas, int dash, \
		size_t j);
int					ft_check_start_n_end(t_check *list, t_info *data);
int					fill_info(t_check *list, t_info *data);
int					ft_skip_hash(t_check **list, t_info *data, int *i);
void				fill_link(t_check *list, t_info *data, size_t i);
void				delete_list(t_check **list);
void				delete_info(t_info **data);
void				delete_arg(char **arg);
long				my_atoll(const char *str, t_check *list, t_info *data, \
		long nb);
void				my_error(t_check *list, t_info *data, int type);
int					ft_create_path(t_info *data, t_check *list);
void				ft_print_sol(t_room *end, t_info *data);

#endif
