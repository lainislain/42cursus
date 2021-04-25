/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 02:26:10 by amaghat           #+#    #+#             */
/*   Updated: 2020/12/02 04:05:56 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct	s_list
{
	char	conv;
	char	flag;
	int		prec;
	int		width;
	int		point;
}				t_convert;

void			ft_gp(t_convert *convert, va_list args, char *str, int *i);
void			ft_gw(t_convert *convert, va_list args, char *str, int *i);
void			ft_get_flag(t_convert *convert, char *str, int *i);
void			ft_spacepadding(t_convert convert, int *res);
void			ft_zeropadding(t_convert convert, int *res, int *nzr);
int				ft_getnzr(t_convert convert, long long num);
int				ft_printf(char *format, ...);
int				ft_printd(t_convert convert, va_list args);
int				ft_printu(t_convert convert, va_list args);
int				ft_printx(t_convert convert, va_list args);
int				ft_prints(t_convert convert, va_list args);
int				ft_printc(t_convert convert, va_list args);
int				ft_manage(t_convert convert, va_list args);
int				ft_atoi(char *s);
int				ft_getnum(long long n, unsigned int base);
int				ft_strlen(char *s);
int				ft_isdigit(char c);
char			*ft_upper(char *str);
char			*ft_itoa_base(unsigned long long n, unsigned int base);
void			ft_xp(t_convert convert, char *str, int *i, int *j);
int				ft_test_conv(char c);
void			ft_print_char(char **format, int *res);
int				ft_printper(t_convert convert);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
void			printd(long long num);

#endif
