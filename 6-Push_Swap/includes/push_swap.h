/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/26 19:01:42 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/11 15:45:52 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								DEFINES									*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

# define PUSH_SWAP_H

/*
**	STRUCTURE ELEMENTS
*/

# define VAL_A1 a->next->val
# define VAL_A2 a->next->next->val
# define VAL_A3 a->next->next->next->val
# define VAL_A0 a->prev->val
# define VAL_B1 b->next->val
# define VAL_B2 b->next->next->val
# define VAL_B3 b->next->next->next->val
# define VAL_B0 b->prev->val

/*
**	ALIAS TO CALL FUNCTIONS
*/

# define PA ft_pa(a, b, i)
# define PB ft_pb(a, b, i)
# define SA ft_sa(a, b, i)
# define SB ft_sb(a, b, i)
# define SS ft_ss(a, b, i)
# define RA ft_ra(a, b, i)
# define RB ft_rb(a, b, i)
# define RR ft_rr(a, b, i)
# define RRA ft_rra(a, b, i)
# define RRB ft_rrb(a, b, i)
# define RRR ft_rrr(a, b, i)

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								INCLUDES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

# include "../libft/includes/printf.h"

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								STRUCTURES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

typedef struct		s_dllist
{
	intmax_t		val;
	intmax_t		length;
	int				med;
	int				min;
	int				min_hits;
	int				max;
	int				max_hits;
	int				to_push;
	int				push : 1;
	int				print;
	int				moves;
	intmax_t		tot;
	intmax_t		sortednb;
	intmax_t		rest;
	struct s_dllist	*next;
	struct s_dllist	*prev;
}					t_dllist;

/*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
**	*								PROTOTYPES								*
**	*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*~*
*/

/*
**	MAIN FUNCTIONS
*/
int					main(int argc, char **argv);
int					ft_check_errors(int argc, char **argv, t_dllist **a, \
		t_dllist **b);
int					ft_isnb(int i, char **argv);
void				ft_putarg_inlst(t_dllist **a, t_dllist **b, int t, \
		int *tab);

/*
**	MOVE FUNCTIONS
*/
void				ft_sa(t_dllist *a, t_dllist *b, int i);
void				ft_sb(t_dllist *a, t_dllist *b, int i);
void				ft_ss(t_dllist *a, t_dllist *b, int i);
void				ft_ra(t_dllist *a, t_dllist *b, int i);
void				ft_rb(t_dllist *a, t_dllist *b, int i);
void				ft_rr(t_dllist *a, t_dllist *b, int i);
void				ft_rra(t_dllist *a, t_dllist *b, int i);
void				ft_rrb(t_dllist *a, t_dllist *b, int i);
void				ft_rrr(t_dllist *a, t_dllist *b, int i);
void				ft_pa(t_dllist *a, t_dllist *b, int i);
void				ft_pb(t_dllist *a, t_dllist *b, int i);

/*
**	SORTING FUNCTIONS
*/
void				ft_sort_little(t_dllist *a, t_dllist *b, int i);
void				ft_sort_little_inb(t_dllist *a, t_dllist *b, int i);
void				ft_sort_medium(t_dllist *a, t_dllist *b, int i);
void				ft_real_sort(t_dllist *a, t_dllist *b, int i);
void				ft_mini_sortb(t_dllist *a, t_dllist *b, int i);
void				ft_sort_three_inb(t_dllist *a, t_dllist *b, int i);
int					ft_repush(t_dllist *a, t_dllist *b, int i, intmax_t *nb);
int					ft_deal_bigx(t_dllist *a, t_dllist *b, int i, intmax_t x);
void				ft_deal_three(t_dllist *a, t_dllist *b, int i);
void				ft_ins_sort(t_dllist *a, t_dllist *b, int i);
void				ft_decide(t_dllist *a, t_dllist *b, int i);

/*
**	BONUS FONCTIONS : PRINTING LISTS
*/
void				ft_printlists(t_dllist *a, t_dllist *b);
void				ft_quick_sort(t_dllist *a, t_dllist *b, int i);

#endif
