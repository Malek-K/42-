/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alima <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/09 14:35:46 by alima             #+#    #+#             */
/*   Updated: 2017/11/09 14:58:23 by alima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
	int i;

	i = 0;
	if (n <= 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && s2[i] && i < (int)n - 1)
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}
