/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 00:08:49 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/09 04:38:28 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t	ft_strlen2(const char *s)

{
	size_t	count;

	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

int	ft_isdigit2(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int	ft_atoi2(const char *nptr)
{
	int	i;
	int	mult;
	int	n;

	n = 0;
	i = 0;
	mult = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '-')
	{
		mult = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (ft_isdigit2(nptr[i]) == 1)
	{
		n = 10 * n + nptr[i] - '0';
		i++;
	}
	return (mult * n);
}

char	*ft_strchr2(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if ((unsigned char) s[i] == (unsigned char) c)
			return ((char *)(s + i));
		i++;
	}
	if (c == '\0')
		return ((char *)(s + i));
	else
		return (NULL);
}
