/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex_bonus copy.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/25 18:49:13 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/05 02:11:53 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_puthex(unsigned long const p, size_t prefix, int padd, char flag)
{
	char	*hexa;
	size_t	len;

	len = 0;
	if (p == 0)
		prefix = 0;
	if (p == 0 && padd == 0 && flag == '.')
		return (0);
	if (prefix == 1)
		len += write (1, "0x", 2);
	if (padd > 0)
	len += ft_padding_hex(p, padd, flag);
	hexa = "0123456789abcdef";
	if (p > 15)
		len += ft_puthex(p / 16, 0, 0, '\0');
	len += write(1, &hexa[p % 16], 1);
	len = ft_padding_right(len, padd);
	return (len);
}
