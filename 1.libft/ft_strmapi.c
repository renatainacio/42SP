/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 01:42:16 by rinacio           #+#    #+#             */
/*   Updated: 2022/05/26 03:57:46 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		count;
	char	*strmapi;

	if (!s || !f)
		return (NULL);
	count = ft_strlen(s);
	strmapi = (char *) malloc ((count + 1) * sizeof(char));
	if (strmapi == NULL)
		return (NULL);
	strmapi[count] = '\0';
	count--;
	while (count >= 0)
	{
		strmapi[count] = f(count, s[count]);
		count--;
	}
	return (strmapi);
}
