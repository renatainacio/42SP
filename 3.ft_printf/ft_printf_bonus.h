/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/05 00:40:29 by rinacio           #+#    #+#             */
/*   Updated: 2022/08/04 22:52:40 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_BONUS_H
# define FT_PRINTF_BONUS_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);

size_t	ft_putchar(char c, int n, char flag);

size_t	ft_putnbr(int long n, int padding, char flag);

size_t	ft_putstr(const char *s, int n, char flag);

char	*ft_strchr(const char *s, int c);

size_t	ft_strlen(const char *s);

size_t	ft_puthex(unsigned long const p, size_t prefix, int padd, char flag);

size_t	ft_putuphex(unsigned long const p, size_t prefix, int padd, char flag);

int		ft_atoi(const char *nptr);

char	*ft_itoa(int long n);

int		ft_nflag(int *i, const char *format, char flag);

size_t	ft_putptr(unsigned long const p, int prefix, int padd);

size_t	ft_padding_left(int long n, int padding, char flag);

size_t	ft_padding_right(size_t len, int padding);

size_t	ft_padding_hex(unsigned long const p, int padd, char flag);

int		hexdigits(unsigned long p);

#endif