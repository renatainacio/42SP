/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   min_max.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:36:53 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 13:40:31 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_value_a(t_data *data)
{
	t_element	*aux;
	int			i;
	int			max;
	int			max_index;

	aux = data->stack_a.start;
	i = 0;
	max_index = 0;
	max = data->stack_a.start->elem;
	while (aux)
	{
		if (aux->elem > max)
		{
			max = aux->elem;
			max_index = i;
		}
		aux = aux->next;
		i++;
	}
	return (max_index);
}

int	min_value_a(t_data *data)
{
	t_element	*aux;
	int			i;
	int			min;
	int			min_index;

	aux = data->stack_a.start;
	i = 0;
	min_index = 0;
	min = data->stack_a.start->elem;
	while (aux)
	{
		if (aux->elem < min)
		{
			min = aux->elem;
			min_index = i;
		}
		aux = aux->next;
		i++;
	}
	return (min_index);
}
