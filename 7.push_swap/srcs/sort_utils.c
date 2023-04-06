/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 17:21:03 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 13:36:49 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	multiple_rotations(t_stack *stack, int i)
{
	int	rotations;

	rotations = 0;
	while (rotations < i)
	{
		rotate(stack);
		rotations++;
	}
}

int	count_keep_in_a(t_data *data, int i)
{
	int			rotations;
	int			count;
	int			elem_ref;
	t_element	*aux;

	rotations = 0;
	count = 1;
	multiple_rotations(&data->stack_aux, i);
	aux = data->stack_aux.start;
	elem_ref = aux->elem;
	while (aux)
	{
		if (aux->elem > elem_ref)
		{
			count++;
			elem_ref = aux->elem;
		}
		aux = aux->next;
	}
	multiple_rotations(&data->stack_aux, data->nargs - i);
	return (count);
}

void	find_max(int *arr, int size, t_data *data)
{
	int	i;
	int	max;

	i = 0;
	max = arr[0];
	data->head.head_index = 0;
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
			data->head.head_index = i;
		}
		i++;
	}
}

int	find_min(int *arr, int size)
{
	int	i;
	int	min;
	int	min_index;

	i = 0;
	min_index = 0;
	min = arr[0];
	while (i < size)
	{
		if (arr[i] < min)
		{
			min = arr[i];
			min_index = i;
		}
		i++;
	}
	return (min_index);
}
