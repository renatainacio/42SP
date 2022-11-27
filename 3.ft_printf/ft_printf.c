/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 02:31:51 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/05 02:10:43 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_parse(char c, va_list args, int n, char flag);

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		len;
	int		i;
	int		n;
	char	flag;

	va_start(args, format);
	i = 0;
	len = 0;
	while (format[i])
	{
		if (format[i] != '%')
			len += write (1, &format[i], 1);
		else if (ft_strchr("0-.123456789#+ ", format[i + 1]))
		{
			flag = format[++i];
			n = ft_nflag(&i, format, flag);
			len += ft_parse(format[i++ + 1], args, n, flag);
		}
		else
			len += ft_parse(format[i++ + 1], args, 0, 0);
		i++;
	}
	va_end(args);
	return (len);
}

int	ft_parse(char c, va_list args, int n, char flag)
{
	int	len;

	len = 0;
	if (c == 'i' || c == 'd')
		len += ft_putnbr(va_arg(args, int), n, flag);
	else if (c == 'u')
		len += ft_putnbr(va_arg(args, unsigned int), n, flag);
	else if (c == 'c')
		len += ft_putchar(va_arg(args, int), n, flag);
	else if (c == 's')
		len += ft_putstr(va_arg(args, char *), n, flag);
	else if (c == '%')
		len += write(1, "%", 1);
	else if (c == 'p')
		len += ft_putptr(va_arg(args, unsigned long), 1, n);
	else if (c == 'x' && flag == '#')
		len += ft_puthex(va_arg(args, unsigned int), 1, n, flag);
	else if (c == 'x' && flag != '#')
		len += ft_puthex(va_arg(args, unsigned int), 0, n, flag);
	else if (c == 'X' && flag == '#')
		len += ft_putuphex(va_arg(args, unsigned int), 1, n, flag);
	else if (c == 'X' && flag != '#')
		len += ft_putuphex(va_arg(args, unsigned int), 0, n, flag);
	return (len);
}
