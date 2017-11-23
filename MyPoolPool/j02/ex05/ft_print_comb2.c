/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 11:28:51 by mkamel            #+#    #+#             */
/*   Updated: 2017/09/04 16:37:29 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putchar(char c);

char	print(char a, char b, char c, char d)
{
	if ((a + b) < (c + d))
	{
		ft_putchar(a);
		ft_putchar(b);
		ft_putchar(' ');
		ft_putchar(c);
		ft_putchar(d);
		if (a == '9' && b == '8' && c == '9' && d == '9')
			ft_putchar('\0');
		else
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
	}
	return (d + 1);
}

void	ft_print_comb2(void)
{
	int a;
	int b;
	int c;
	int d;

	a = '0';
	while (a <= '9')
	{
		b = '0';
		while (b <= '9')
		{
			c = '0';
			while (c <= '9')
			{
				d = '0';
				while (d <= '9')
				{
					d = print(a, b, c, d);
				}
				c++;
			}
			b++;
		}
		a++;
	}
}
