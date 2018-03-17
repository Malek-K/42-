/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/21 15:37:54 by mkamel            #+#    #+#             */
/*   Updated: 2017/11/21 17:20:54 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*lst;

	while (*alst)
	{
		lst = (*alst)->next;
		del((*alst)->content, (*alst)->content_size);
		free(*alst);
		*(alst) = lst;
	}
	*alst = NULL;
}
