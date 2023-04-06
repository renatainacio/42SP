/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 05:38:25 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 05:39:04 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_is_sorted(t_stack *stack)
{
	t_element	*aux;

	aux = stack->start;
	while (aux->next)
	{
		if (aux->next->elem < aux->elem)
			return (0);
		aux = aux->next;
	}
	return (1);
}

void	swap(int *a, int *b)
{
	int	aux;

	aux = *a;
	*a = *b;
	*b = aux;
}

int	match_index(t_data *data, int elem)
{
	int	i;

	i = 0;
	while (i < data->nargs)
	{
		if (elem == data->args[i])
			return (i);
		i++;
	}
	return (0);
}

void	indexation(t_data *data)
{
	int			i;
	t_element	*aux;

	while (!is_sorted(data, 0))
	{
		i = 1;
		while (i < data->nargs)
		{
			if (data->args[i] < data->args[i - 1])
				swap(&data->args[i], &data->args[i - 1]);
			i++;
		}
	}
	aux = data->stack_a.start;
	while (aux)
	{
		aux->index = match_index(data, aux->elem);
		aux = aux->next;
	}
}

void	create_aux(t_data *data)
{
	t_element	*aux;
	t_element	*new_elem;

	data->stack_aux.size = 0;
	data->stack_aux.start = NULL;
	aux = data->stack_a.start;
	while (aux)
	{
		new_elem = (t_element *)malloc(sizeof(t_element));
		if (!new_elem)
			ft_error(1, 6, data);
		new_elem->elem = aux->elem;
		new_elem->index = aux->index;
		new_elem->prev = NULL;
		new_elem->next = NULL;
		add_elem_end_stack(&data->stack_aux, new_elem);
		aux = aux->next;
	}
}
