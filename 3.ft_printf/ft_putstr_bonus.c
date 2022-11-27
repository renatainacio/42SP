/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/22 23:44:46 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/05 02:12:55 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_straux(int i, int len, int n, char flag);

size_t	ft_putstr(const char *s, int n, char flag)
{
	int	len;
	int	i;

	if (!s && n == 0 && flag == '.')
		return (0);
	if (!s)
		return (write(1, "(null)", 6));
	i = 0;
	len = ft_strlen(s);
	if (flag != '.' & n > len && len > 0)
	{
		while (i++ < n - len)
			write (1, " ", 1);
		i--;
		while (i < n)
			ft_putchar(s[i++ - n + len], 0, '\0');
	}
	i += ft_straux(i, len, n, flag);
	while ((i < len && flag != '.') || (i < len && flag == '.' && i < n))
		ft_putchar(s[i++], 0, '\0');
	while (i++ < -n)
		write(1, " ", 1);
	i--;
	return (i);
}

int	ft_straux(int i, int len, int n, char flag)
{
	if (flag != '.' && len == 0)
	{
		while (i++ < n)
			write (1, " ", 1);
		i--;
	}
	return (i);
}
