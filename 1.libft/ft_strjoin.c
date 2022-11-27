/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/18 23:22:31 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:57:36 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*joined;
	int		len_s1;
	int		len_s2;
	int		i;

	len_s1 = ft_strlen(s1);
	len_s2 = ft_strlen(s2);
	joined = (char *) malloc(len_s1 * sizeof(*s1) + (len_s2 + 1) * sizeof(*s2));
	if (joined == NULL)
		return (NULL);
	i = 0;
	while (i < len_s1)
	{
		joined[i] = s1[i];
		i++;
	}
	while (i < len_s1 + len_s2)
	{
		joined[i] = s2[i - len_s1];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}
