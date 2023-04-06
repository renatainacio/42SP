/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/19 20:18:34 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:57:23 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *s, char c);

static char	**ft_free(char **split, int count);

static int	ft_next(char **s, char c, int next_len);

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		i;
	char	*next;
	int		next_len;

	if (!s)
		return (NULL);
	split = (char **) malloc(sizeof(char *) * (ft_count(s, c) + 1));
	if (split == NULL)
		return (ft_free(split, ft_count(s, c)));
	i = 0;
	next = (char *) s;
	next_len = 0;
	while (i < ft_count(s, c))
	{
		next_len = ft_next(&next, c, next_len);
		split[i] = (char *) malloc(sizeof(char) * (next_len + 1));
		if (split == NULL)
			return (ft_free(split, ft_count(s, c)));
		ft_strlcpy(split[i], next, next_len + 1);
		i++;
	}
	split[i] = 0;
	return (split);
}

static int	ft_count(char const *s, char c)
{
	int	i;
	int	count;

	if (!s[0])
		return (0);
	i = 0;
	count = 0;
	while (s[i] != '\0' && s[i] == c)
		i++;
	while (s[i] != '\0')
	{
		if (s[i] == c)
		{
			count++;
			while (s[i] != '\0' && s[i] == c)
				i++;
			continue ;
		}
		i++;
	}
	if (s[i - 1] != c)
		count++;
	return (count);
}

static char	**ft_free(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	ft_next(char **next, char c, int next_len)
{
	*next = *next + next_len;
	next_len = 0;
	while (**next == c)
		(*next)++;
	while (**next != '\0')
	{
		if (**next == c)
		{
			(*next) = (*next) - next_len;
			return (next_len);
		}
		next_len++;
		(*next)++;
	}
	(*next) = (*next) - next_len;
	return (next_len);
}
