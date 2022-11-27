/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 19:42:12 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:58:02 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	strlen;
	size_t	i;

	if (!s)
		return (NULL);
	strlen = ft_strlen(s);
	if (start >= strlen)
		return (ft_strdup(""));
	if (len > strlen - start)
		len = strlen - start;
	substr = (char *) malloc((len + 1) * sizeof(*s));
	if (substr == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		((unsigned char *)substr)[i] = ((unsigned const char *)s)[i + start];
		i++;
	}
	substr[len] = '\0';
	return (substr);
}
