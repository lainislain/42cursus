/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_manage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 01:39:04 by amaghat           #+#    #+#             */
/*   Updated: 2020/11/29 02:13:52 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_spacepadding(t_convert convert, int *res)
{
	if (convert.flag == '\0')
		while (convert.width > (*res)++)
			write(1, " ", 1);
	if (convert.flag == '0' && convert.prec >= 0)
		while (convert.width > (*res)++)
			write(1, " ", 1);
}

void		ft_zeropadding(t_convert convert, int *res, int *nzr)
{
	while ((*nzr)--)
		write(1, "0", 1);
	if (convert.flag == '0' && convert.prec < 0)
		while (convert.width > (*res)++)
			write(1, "0", 1);
}

int			ft_manage(t_convert convert, va_list args)
{
	if (convert.conv == 'u')
		return (ft_printu(convert, args));
	if (convert.conv == 's')
		return (ft_prints(convert, args));
	if (convert.conv == 'c')
		return (ft_printc(convert, args));
	if (convert.conv == 'x' || convert.conv == 'X' || convert.conv == 'p')
		return (ft_printx(convert, args));
	if (convert.conv == 'd' || convert.conv == 'i')
		return (ft_printd(convert, args));
	if (convert.conv == '%')
		return (ft_printper(convert));
	else
		return (0);
}

void		ft_xp(t_convert convert, char *str, int *i, int *j)
{
	char	*s;

	if (convert.conv == 'p')
		write(1, "0x", 2);
	ft_zeropadding(convert, i, j);
	if (!ft_strncmp(str, "0", 2) && convert.point > 0
	&& !convert.prec)
	{
	}
	else
	{
		if (convert.conv == 'x' || convert.conv == 'p')
		{
			write(1, str, ft_strlen(str));
		}
		else
		{
			s = ft_upper(str);
			write(1, s, ft_strlen(s));
			free(s);
			s = NULL;
		}
	}
}
