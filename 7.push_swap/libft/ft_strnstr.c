/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 23:42:22 by rinacio           #+#    #+#             */
/*   Updated: 2022/04/29 23:46:55 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char	*big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	size_t	temp;
	size_t	len_little;

	len_little = ft_strlen(little);
	i = 0;
	if (little[0] == '\0')
		return ((char *)(big));
	while (big[i] != '\0' && i < len)
	{
		j = 0;
		temp = i;
		while (little[j] != '\0' && big[i] == little[j] && i < len)
		{
			if (j == len_little - 1)
				return ((char *)(big + i - j));
			i++;
			j++;
		}
		i = temp + 1;
	}
	return (NULL);
}
