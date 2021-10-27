/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaghat <amaghat@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/27 15:35:48 by amaghat           #+#    #+#             */
/*   Updated: 2021/10/27 15:35:48 by amaghat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <limits.h>

int ft_putchar(char c)
{
    write(1, &c, 1);
    return (1);
}

int ft_putnbr(unsigned int c, int base_len)
{
    char *base = "0123456789abcdef";
    if (c >= base_len)
        ft_putnbr(c / base_len, base_len);
    write(1, &base[c % base_len], 1);
    return (1);
}

int ft_printfd(int c)
{
    int i;
    int count;

    count = 0;
    if (c < 0)
    {
        c = -c;
        count += ft_putchar('-');
    }
    count += ft_putnbr(c, 10);
    return (count);
}

int ft_printfs(char *s)
{
    int len;
    int count;

    len = 0;
    count = 0;
    if (s == NULL)
        s = "(null)";
    while (s[len])
    {
        count += ft_putchar(s[len]);
        len++;
    }
    return (count);
}

int ft_printf(const char *fmt, ...)
{
    va_list ap;
    int     i;
    int     count;

    if (fmt == NULL)
        return (0);
    va_start(ap, fmt);
    count = 0;
    i = 0;
    while (fmt[i])
    {
        if (fmt[i] == '%')
        {
            i++;
            if (fmt[i] == 's')
                count += ft_printfs(va_arg(ap, char *));
            if (fmt[i] == 'd')
                count += ft_printfd(va_arg(ap, int));
            if (fmt[i] == 'x')
                count += ft_putnbr(va_arg(ap, unsigned int), 16);
        }
        else
            count += ft_putchar(fmt[i]);
        i++;
    }
    va_end(ap);
    return (count);
}

int main()
{
    ft_printf("%s\n", "hello");
    printf("%s\n", "hello");
}