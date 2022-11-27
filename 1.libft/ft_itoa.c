/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 21:28:34 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:56:18 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digits(int n);

static int	ft_nextnumber(int n);

char	*ft_itoa(int n)
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

static int	ft_digits(int n)
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

static int	ft_nextnumber(int n)
{
	if (n >= 0)
		return ((n % 10) + '0');
	else
		return (-(n % 10) + '0');
}
