/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_lists.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/28 20:14:01 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/03 16:26:44 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#define ELEM_A

static void		ft_print_list_a(t_dllist *a)
{
	t_dllist	*p;
	int			i;

	p = a->next;
	i = 0;
	ft_printf("\n**** | LIST A | ****\n");
	while (p != a)
	{
		ft_printf("=>{cya} { A{whi}[%d] = {red} {bal}%lld{cya} }{eoc} <=", i, \
				p->val);
		(i % 5 == 0) ? ft_printf("\n") : 0;
		p = p->next;
		i++;
	}
	ft_printf("\n*\v**\v***\f**** | A->LENGTH = %d | ****\n\n", a->length);
}

static void		ft_print_list_b(t_dllist *b)
{
	t_dllist	*p;
	int			i;

	p = b->next;
	i = 0;
	ft_printf("\n**** | LIST B | ****\n");
	while (p != b)
	{
		ft_printf("=>{yel} { B{whi}[%d] = {red} {bal}%lld{yel} }{eoc} <=", i, \
				p->val);
		(i % 5 == 0) ? ft_printf("\n") : 0;
		p = p->next;
		i++;
	}
	ft_printf("\n*\v**\v***\f**** | B->LENGTH = %d | ****\n\n", b->length);
}

void			ft_printlists(t_dllist *a, t_dllist *b)
{
	ft_print_list_a(a);
	ft_print_list_b(b);
}
