/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 11:48:20 by alima             #+#    #+#             */
/*   Updated: 2017/11/27 16:37:00 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(const void *content, size_t content_size)
{
	t_list *new;

	new = (t_list *)malloc(sizeof(*new));
	if (new)
	{
		if (content)
		{
			if ((new->content = malloc(content_size)))
			{
				new->content_size = content_size;
				ft_memcpy(new->content, content, content_size);
			}
		}
		else
		{
			new->content = NULL;
			new->content_size = 0;
		}
		new->next = NULL;
	}
	else
		return (NULL);
	return (new);
}
