/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/11 19:11:32 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/13 21:22:47 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcapitalize(char *str)
{
	int i;

	i = 0;
	if (str[i] == 0)
		return (str);
	if (str[0] > 96 && str[0] < 123)
		str[0] = str[0] - 32;
	i++;
	while (str[i] != '\0')
	{
		if ((str[i - 1] < 97 && str[i - 1] > 90) || str[i - 1] > 122
				|| (str[i - 1] < 65 && str[i - 1] > 57) || str[i - 1] < 48)
		{
			if (str[i] > 96 && str[i] < 123)
				str[i] = str[i] - 32;
		}
		else if (str[i] > 64 && str[i] < 91)
			str[i] = str[i] + 32;
		i++;
	}
	return (str);
}
