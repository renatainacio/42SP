/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 00:02:56 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/09 04:39:25 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putnbr2(int long n, int padding, char flag)
{
	size_t	len;

	len = 0;
	if (n >= 0 && (flag == '+' || flag == ' '))
	{
		write (1, &flag, 1);
		len++;
	}
	if (n == 0 && padding == 0 && flag == '.')
		return (0);
	if (padding > 0 && flag != '0' && flag != '.')
		len += ft_padding_left(n, padding, flag);
	if (n < 0)
		len += ft_putchar2('-', 0, '\0');
	if (padding > 0 && (flag == '0' || flag == '.'))
		len += ft_padding_left(n, padding, flag);
	if (n < 0)
		len += ft_putnbr2(-n, 0, '\0');
	else if (n >= 10)
		len += ft_putnbr2(n / 10, 0, '\0');
	if (n >= 0)
		len += ft_putchar2(n % 10 + '0', 0, '\0');
	if (padding < 0)
		len = ft_padding_right(len, padding);
	return (len);
}
