/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:20:49 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/09 04:38:48 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_putchar2(char c, int n, char flag)
{
	int	len;

	len = 0;
	while (flag != '-' && len < n - 1)
		len += write(1, " ", 1);
	len += write(1, &c, 1);
	while (flag == '-' && n + len < 0)
		len += write(1, " ", 1);
	return (len);
}
