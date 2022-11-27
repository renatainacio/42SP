/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_aux_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 23:30:58 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/05 02:14:09 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	ft_nflag(int *i, const char *format, char flag)
{
	int		j;
	int		k;
	char	*nflag;
	int		n;

	if (ft_strchr("0-.#+ ", flag))
		(*i)++;
	j = 0;
	while (ft_strchr("0123456789", format[*i + j]))
		j++;
	nflag = (char *)malloc (sizeof(char *) * (j + 1));
	if (!nflag)
		return (0);
	k = 0;
	while (k < j)
		nflag[k++] = format[(*i)++];
	nflag[j] = '\0';
	n = ft_atoi(nflag);
	free (nflag);
	*i = *i - 1;
	if (flag == '-')
		n = -n;
	return (n);
}

size_t	ft_padding_left(int long n, int padding, char flag)
{
	char	*nbr;
	int		len;

	len = 0;
	if (padding > 0)
	{
		nbr = ft_itoa(n);
		padding = padding - ft_strlen(nbr);
		free(nbr);
		if (n < 0 && flag == '.')
			padding++;
		if (ft_strchr("123456789", flag))
			flag = ' ';
		else
			flag = '0';
		while (padding > 0)
		{
			write (1, &flag, 1);
			len++;
			padding--;
		}
	}
	return (len);
}

size_t	ft_padding_right(size_t len, int padding)
{
	while ((int)len < -padding)
	{
		write(1, " ", 1);
		len++;
	}
	return (len);
}

size_t	ft_padding_hex(unsigned long const p, int padd, char flag)
{
	int	len;
	int	i;

	len = 0;
	i = hexdigits(p);
	if (flag == '.')
		flag = '0';
	if (flag != '0' && flag != '.')
		flag = ' ';
	if (p < 0)
		i = 8 - i;
	padd = padd - i;
	while (padd > 0)
	{
		write (1, &flag, 1);
		padd--;
		len++;
	}
	return (len);
}
