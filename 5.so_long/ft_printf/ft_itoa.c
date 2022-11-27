/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:28:34 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/09 04:25:14 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_digits(int long n);

static int	ft_nextnumber(int long n);

char	*ft_itoa2(int long n)
{
	char	*a;
	int		count;

	count = ft_digits(n);
	if (n < 0)
		count++;
	a = (char *)malloc(sizeof(char) * (count + 1));
	if (a == NULL)
		return (NULL);
	if (n < 0)
		a[0] = '-';
	if (n == 0)
		a[0] = '0';
	a[count] = '\0';
	while (n != 0)
	{
		a[count - 1] = ft_nextnumber(n);
		n = n / 10;
		count--;
	}
	return (a);
}

static int	ft_digits(int long n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

static int	ft_nextnumber(int long n)
{
	if (n >= 0)
		return ((n % 10) + '0');
	else
		return (-(n % 10) + '0');
}
