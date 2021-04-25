/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printconv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 02:20:27 by amaghat           #+#    #+#             */
/*   Updated: 2020/12/02 04:20:39 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printd(t_convert convert, va_list args)
{
	int			nzr;
	int			res;
	long long	num;

	num = (long long)va_arg(args, int);
	nzr = ft_getnzr(convert, num);
	res = nzr + ft_getnum((int)num, 10);
	if (num < 0)
		res++;
	if (num == 0 && convert.prec == 0)
		res = 0;
	ft_spacepadding(convert, &res);
	if (num < 0)
	{
		write(1, "-", 1);
		num *= -1;
	}
	ft_zeropadding(convert, &res, &nzr);
	if (num != 0 || convert.prec != 0)
		printd(num);
	while (convert.flag == '-' && convert.width > res++)
		write(1, " ", 1);
	return (--res);
}

int			ft_printu(t_convert convert, va_list args)
{
	int				nzr;
	int				res;
	unsigned int	num;
	char			*str;

	num = va_arg(args, unsigned int);
	nzr = ft_getnzr(convert, num);
	res = nzr + ft_getnum(num, 10);
	if (num == 0 && convert.prec == 0)
		res = 0;
	ft_spacepadding(convert, &res);
	ft_zeropadding(convert, &res, &nzr);
	if (num != 0 || convert.prec != 0)
	{
		str = ft_itoa_base(num, 10);
		write(1, str, ft_getnum(num, 10));
		free(str);
		str = NULL;
	}
	while (convert.flag == '-' && convert.width > res++)
		write(1, " ", 1);
	return (--res);
}

int			ft_printx(t_convert convert, va_list args)
{
	int			nzr;
	int			res;
	char		*str;

	res = 0;
	if (convert.conv == 'p')
	{
		str = ft_itoa_base(va_arg(args, size_t), 16);
		res += 2;
	}
	else
		str = ft_itoa_base(va_arg(args, unsigned int), 16);
	nzr = 0;
	if (convert.prec >= ft_strlen(str))
		nzr = convert.prec - ft_strlen(str);
	res = res + nzr + ft_strlen(str);
	if (!ft_strncmp(str, "0", 2) && convert.point > 0 && !convert.prec)
		res--;
	ft_spacepadding(convert, &res);
	ft_xp(convert, str, &res, &nzr);
	free(str);
	str = NULL;
	while (convert.flag == '-' && convert.width > res++)
		write(1, " ", 1);
	return (--res);
}

int			ft_prints(t_convert convert, va_list args)
{
	int			res;
	char		*str;

	if (!(str = va_arg(args, char*)))
		str = "(null)";
	if (convert.prec < ft_strlen(str) && convert.prec >= 0)
		res = convert.prec;
	else
		res = ft_strlen(str);
	while (convert.flag != '-' && convert.width > res++)
		write(1, " ", 1);
	if (convert.prec < ft_strlen(str) && convert.prec >= 0)
		write(1, str, convert.prec);
	else
		write(1, str, ft_strlen(str));
	while (convert.flag == '-' && convert.width > res++)
		write(1, " ", 1);
	return (--res);
}

int			ft_printc(t_convert convert, va_list args)
{
	char		c;
	int			res;

	res = 1;
	c = va_arg(args, int);
	while (convert.flag != '-' && convert.width > res++)
		write(1, " ", 1);
	write(1, &c, 1);
	while (convert.flag == '-' && convert.width > res++)
		write(1, " ", 1);
	return (--res);
}
