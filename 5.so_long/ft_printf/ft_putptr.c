/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr_bonus copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:49:13 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/05 02:12:27 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putptr(unsigned long const p, int prefix, int padd)
{
	char	*hexa;
	size_t	len;
	int		i;

	len = 0;
	if (padd > 0)
	{
		if (p == 0)
			i = 5;
		else
			i = hexdigits(p) + 2;
		while ((int)len < padd - i)
			len += write(1, " ", 1);
	}
	if (p == 0)
		return (len + (write(1, "(nil)", 5)));
	if (prefix == 1)
		len += write (1, "0x", 2);
	hexa = "0123456789abcdef";
	if (p > 15)
		len += ft_putptr(p / 16, 0, 0);
	len += write(1, &hexa[p % 16], 1);
	if (padd < 0)
		len = ft_padding_right(len, padd);
	return (len);
}

int	hexdigits(unsigned long p)
{
	int	i;

	i = 0;
	if (p == 0)
		i = 1;
	while (p != 0)
	{
		i++;
		p = p / 16;
	}
	return (i);
}
