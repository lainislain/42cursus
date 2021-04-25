/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 03:04:53 by amaghat           #+#    #+#             */
/*   Updated: 2020/11/12 02:30:05 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_gw(t_convert *convert, va_list args, char *str, int *i)
{
	while (str[*i] == ' ')
	{
		write(1, " ", 1);
		(*i)++;
	}
	if (str[*i] == '*')
	{
		convert->width = va_arg(args, int);
		if (convert->width < 0)
			convert->flag = '-';
		while (str[*i] == '*')
			(*i)++;
	}
	else
	{
		convert->width = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i) += 1;
	}
	if (convert->width < 0)
	{
		convert->width *= -1;
		convert->flag = '-';
	}
}

void		ft_gp(t_convert *convert, va_list args, char *str, int *i)
{
	(*i)++;
	if (str[*i] == '*')
	{
		convert->prec = va_arg(args, int);
		while (str[*i] == '*')
			(*i)++;
	}
	else
	{
		convert->prec = ft_atoi(&str[*i]);
		while (ft_isdigit(str[*i]))
			(*i) += 1;
	}
}

void		ft_get_flag(t_convert *convert, char *str, int *i)
{
	while (str[*i] == '-' || str[*i] == '0')
	{
		if (str[*i] == '0' && convert->flag != '-')
			convert->flag = '0';
		else
			convert->flag = '-';
		(*i)++;
	}
}

int			ft_get_conv(t_convert *convert, va_list args, char *str)
{
	int				i;

	i = 1;
	convert->conv = '\0';
	convert->flag = '\0';
	convert->width = -1;
	convert->prec = -1;
	convert->point = -1;
	ft_get_flag(convert, str, &i);
	ft_gw(convert, args, str, &i);
	if (str[i] == '.')
	{
		ft_gp(convert, args, str, &i);
		convert->point = 1;
	}
	if (ft_test_conv(str[i]))
	{
		convert->conv = str[i];
		return (i);
	}
	else
		return (0);
}

int			ft_printf(char *format, ...)
{
	int				res;
	int				check;
	va_list			args;
	t_convert		convert;

	res = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			ft_print_char(&format, &res);
		else
		{
			check = ft_get_conv(&convert, args, format);
			if (check)
			{
				format += check + 1;
				res += ft_manage(convert, args);
			}
			else
				format += 1;
		}
	}
	return (res);
}
