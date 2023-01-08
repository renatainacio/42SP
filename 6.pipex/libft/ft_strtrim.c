/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:51:25 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:57:57 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_start(char const *s1, char const *set, int len, int len_set);

static int	ft_end(char const *s1, char const *set, int len, int len_set);

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*trimmed;
	unsigned int	len;
	int				len_set;
	int				start;
	int				end;

	if (!s1 || !set)
		return (NULL);
	len = ft_strlen(s1);
	len_set = ft_strlen(set);
	start = ft_start(s1, set, len, len_set);
	end = ft_end(s1, set, len, len_set);
	if (end >= start)
	{
		trimmed = (char *) malloc(sizeof(*s1) * (end - start + 2));
		if (trimmed == NULL)
			return (NULL);
		ft_strlcpy(trimmed, (char *)&s1[start], end - start + 2);
	}
	else
		trimmed = ft_strdup("");
	return (trimmed);
}

int	ft_start(char const *s1, char const *set, int len, int len_set)
{
	int	i;
	int	start;

	start = 0;
	while (start < len)
	{
		i = 0;
		while (i < len_set)
		{
			if (set[i] == s1[start])
				break ;
			else
				i++;
		}
		if (i == len_set)
			break ;
		start++;
	}
	return (start);
}

int	ft_end(char const *s1, char const *set, int len, int len_set)
{
	int	i;
	int	end;

	end = len - 1;
	while (end > 0)
	{
		i = 0;
		while (i < len_set)
		{
			if (set[i] == s1[end])
				break ;
			else
				i++;
		}
		if (i == len_set)
			break ;
		end--;
	}
	return (end);
}
