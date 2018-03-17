/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 21:51:15 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/21 22:32:28 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*fresh;
	t_list	*tmp;
	t_list	*start;

	tmp = f(lst);
	fresh = ft_lstnew(tmp->content, tmp->content_size);
	start = fresh;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		fresh->next = ft_lstnew(tmp->content, tmp->content_size);
		fresh = fresh->next;
		lst = lst->next;
	}
	return (start);
}
