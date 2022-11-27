/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 04:31:35 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/23 06:02:43 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	len_dst;

	len_dst = ft_strlen(dst);
	if (size < len_dst)
		return (size + ft_strlen(src));
	if (size != 0)
	{
		i = len_dst;
		j = 0;
		while (src[j] != '\0' && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (len_dst + ft_strlen(src));
}
