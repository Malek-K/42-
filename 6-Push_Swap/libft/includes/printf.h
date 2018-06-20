/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamel <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/26 14:08:46 by mkamel            #+#    #+#             */
/*   Updated: 2018/03/26 18:55:23 by mkamel           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "../libft_orig/libft.h"

typedef struct		s_data
{
	unsigned int	hash : 1;
	unsigned int	zero : 1;
	unsigned int	minus : 1;
	unsigned int	plus : 1;
	unsigned int	space : 1;
	unsigned int	p_err : 1;

	unsigned int	p_field : 1;
	size_t			precision;
	size_t			width;
	unsigned int	w_field : 1;
	unsigned int	size : 3;
	unsigned int	dbl : 1;

	unsigned int	f_field : 1;
	wchar_t			flag;
	char			*flag_ptr;

	char			*buf;
	char			*f_str;
	char			*start_ptr;
	size_t			length_f;
	size_t			length_bf;
	size_t			ret;
	intmax_t		octet;
}					t_data;

int					ft_printf(const char *format, ...);
void				ft_check_color(const char **format, t_data *arg);
void				ft_checks(va_list *ap, va_list *bp, const char **format, \
		t_data *arg);
void				ft_check_prepends(va_list *ap, va_list *bp, char *cpy,\
		t_data *arg);
void				ft_check_precision(char *cpy, t_data *arg);
void				ft_check_width(char *cpy, t_data *arg);
void				ft_check_size(char *cpy, t_data *arg);
void				ft_check_flag(char *cpy, t_data *arg);
void				ft_doublecheck(t_data *arg);
int					ft_length(t_data *arg, char *f_str);
void				ft_create_buf(char **f_str, t_data *arg);
void				ft_pwdeal(char **f_str, t_data *arg, int neg, size_t *i);

typedef struct		s_funk
{
	char			*(*ptrfunc)(va_list *ap, t_data *arg);
	char			flag;
}					t_funk;

char				*ft_type_conv(va_list *ap, t_data *arg);
uintmax_t			ft_size_conv_uint(uintmax_t nb, t_data *arg);
intmax_t			ft_size_conv_int(intmax_t nb, t_data *arg);
char				*ft_flag_s(va_list *ap, t_data *arg);
char				*ft_flag_cap_s(va_list *ap, t_data *arg);
char				*ft_flag_p(va_list *ap, t_data *arg);
char				*ft_flag_d(va_list *ap, t_data *arg);
char				*ft_flag_cap_d(va_list *ap, t_data *arg);
char				*ft_flag_i(va_list *ap, t_data *arg);
char				*ft_flag_o(va_list *ap, t_data *arg);
char				*ft_flag_cap_o(va_list *ap, t_data *arg);
char				*ft_flag_u(va_list *ap, t_data *arg);
char				*ft_flag_cap_u(va_list *ap, t_data *arg);
char				*ft_flag_x(va_list *ap, t_data *arg);
char				*ft_flag_cap_x(va_list *ap, t_data *arg);
char				*ft_flag_c(va_list *ap, t_data *arg);
char				*ft_flag_cap_c(va_list *ap, t_data *arg);
char				*ft_flag_b(va_list *ap, t_data *arg);
char				*ft_flag_n(va_list *ap, t_data *arg);
char				*ft_flag_f(va_list *ap, t_data *arg);

#endif
