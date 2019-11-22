/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fcahill <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/26 19:16:08 by fcahill           #+#    #+#             */
/*   Updated: 2019/02/26 14:18:20 by fcahill          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft.h"

typedef struct	s_flag
{
	int			left;
	int			width;
	int			precision;
	int			plus;
	int			zero;
	int			hashtag;
	int			space;
	int			i;
	int			l;
	int			ll;
	int			h;
	int			hh;
	int			ret;
	int			neg;
	int			j;
	int			z;
	int			test;
	char		*str;
	int			x;
}				t_flag;

t_flag			ft_putstrb(t_flag flag, char const *s, int max);
t_flag			ft_pfputnbr(t_flag flag, long long n, int precision);
t_flag			ft_uputnbr(t_flag flag, unsigned long long n, int precision);
t_flag			ft_printfloat(char *p1, char *p2, t_flag flag, int len);
t_flag			ft_buffer(t_flag flag, char c);
int				ft_printf(char *fmt, ...);
char			*ft_itoa_base(long long value, int base, int cap);
char			*ft_uitoa_base(long long unsigned value, int base, int cap);
char			*ft_itoa_float(long double n, t_flag flag);
int				ft_unumlen(unsigned long long n);
char			*ft_roundstr(t_flag flag, char *p1, char *p2, int end);
t_flag			ft_readflags(t_flag flag, char *p, va_list ap);
t_flag			ft_specifiers(t_flag flag, char *p);
t_flag			ft_errorcheck(t_flag flag, char *p, int len);
t_flag			ft_returnerror(t_flag flag);
t_flag			ft_readu(t_flag flag, char *p, va_list ap);
t_flag			ft_read(t_flag flag, char *p, va_list ap);
t_flag			ft_int(t_flag flag, long long ival);
t_flag			ft_octal(t_flag flag, char *oval);
t_flag			ft_str(t_flag flag, char *sval);
t_flag			ft_percent(t_flag flag);
t_flag			ft_char(t_flag flag, char cval);
t_flag			ft_hex(t_flag flag, char p, char *xval);
t_flag			ft_point(t_flag flag, char *pval);
t_flag			ft_unint(t_flag flag, unsigned long long uval);
t_flag			ft_float(t_flag flag, long double fval);
t_flag			ft_binary(t_flag flag, char *oval);
#endif
