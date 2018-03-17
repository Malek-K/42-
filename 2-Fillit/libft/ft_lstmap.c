/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 13:45:10 by alima             #+#    #+#             */
/*   Updated: 2017/11/20 16:56:38 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*actual;
	t_list	*one;

	if (lst && f)
	{
		one = (*f)(lst);
		actual = one;
		lst = lst->next;
		while (lst)
		{
			actual->next = (*f)(lst);
			actual = actual->next;
			lst = lst->next;
		}
		return (one);
	}
	else
		return (NULL);
}
