/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putarg_inlst.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <mkamel@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/27 15:26:14 by mkamel            #+#    #+#             */
/*   Updated: 2018/05/05 17:49:34 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
**	MALLOC THE ROOT OF THE CIRCULAR DOUBLE LINKED LIST
**	AND PUT THE DIFFERENT INTS TO ZERO, THE NEXT AND PREV POINTER TO ROOT
*/

static void		ft_create_root(t_dllist **root)
{
	(*root) = (t_dllist*)malloc(sizeof(**root));
	if (root != NULL)
	{
		(*root)->val = 0;
		(*root)->length = 0;
		(*root)->prev = *root;
		(*root)->next = *root;
	}
}

/*
**	APPEND A NEW ELEMENT BETWEEN THE ROOT AND THE PRESENT FIRST ELEMENT
**	IF NO ELEMENT BUT THE ROOT, PUT THE NEW ELEMENT BETWEEN THE NEXT AND
**		THE PREV OF THE ROOT
*/

static t_dllist	*ft_list_prepend(t_dllist *root, int data)
{
	t_dllist	*new_link;

	new_link = malloc(sizeof(*new_link));
	if (root != NULL)
	{
		if (new_link != NULL)
		{
			new_link->val = data;
			new_link->prev = root;
			if (root->prev == root)
			{
				new_link->next = root;
				root->next = new_link;
				root->prev = new_link;
			}
			else
			{
				root->next->prev = new_link;
				new_link->next = root->next;
				root->next = new_link;
			}
		}
	}
	return (root);
}

/*
**	PUT ALL THE ELEMENTS FROM THE TAB IN THE ALREADY ALLOCATED LIST A
*/

static void		ft_create_list(int i, t_dllist **root, int *tab)
{
	int			data;

	while (i > 0)
	{
		data = tab[i - 1];
		*root = ft_list_prepend(*root, data);
		i--;
	}
}

/*
**	GIVE TO A->MED ITS VALUE, THE MEDIAN FROM THE TAB. IF THE NUMBER OF ELEMENTS
**	IS PAIR, TAKES THE BIGGEST ONE OF THE TWO MEDIAN ELEMENTS.
*/

static void		ft_givemed(int i, t_dllist **r, int *tab)
{
	int			x;

	x = 0;
	ft_sort_int_tab(tab, i);
	(*r)->med = tab[i / 2];
}

/*
**	ALLOCATES THE MEMORY FOR THE ROOTS AND THEN CREATE THE DIFFERENT ELEMENTS
**	OF LIST A WHILE READING THE TAB.
**	THE LENGTH OF THE LIST IS EQUAL TO THE NUMBER OF THE ELEMENTS IN TAB.
**	THEN DEFINE THE MEDIAN OF THE LIST, AND THE MINIMUM VALUE OF IT.
*/

void			ft_putarg_inlst(t_dllist **a, t_dllist **b, int t, int *tab)
{
	ft_create_root(a);
	ft_create_root(b);
	(*a)->length = t;
	ft_create_list(t, a, tab);
	ft_givemed(t, a, tab);
	(*a)->min = tab[0];
}
