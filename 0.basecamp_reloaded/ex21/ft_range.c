/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 03:01:01 by rinacio           #+#    #+#             */
/*   Updated: 2022/04/02 07:29:18 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*range;
	int	i;

	if (min >= max)
		return (NULL);
	range = malloc ((max - min) * sizeof (int));
	range[0] = min;
	i = 1;
	while (i < max - min)
	{
		range[i] = range[i - 1] + 1;
		i++;
	}
	return (range);
}
