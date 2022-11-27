/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 16:31:47 by rinacio           #+#    #+#             */
/*   Updated: 2022/06/24 17:05:21 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)

{
	size_t	count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	int		len_s1;
	int		i;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char *));
		s1[0] = '\0';
	}
	if (!s1 || !s2)
		return (NULL);
	len_s1 = ft_strlen(s1);
	joined = (char *) malloc((len_s1 + ft_strlen(s2) + 1) * sizeof(char));
	if (joined == NULL)
		return (NULL);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	i--;
	while (s2[++i - len_s1])
		joined[i] = s2[i - len_s1];
	joined[i] = '\0';
	free(s1);
	return (joined);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!s)
		return (0);
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
