/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_stacks_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 22:32:32 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 05:32:45 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	build_stacks(t_data *data)
{
	int			i;
	t_element	*new_elem;

	data->stack_a.start = NULL;
	data->stack_b.start = NULL;
	data->stack_a.size = 0;
	data->stack_b.size = 0;
	i = 0;
	while (i < data->nargs)
	{
		new_elem = (t_element *)malloc(sizeof(t_element));
		if (!new_elem)
			ft_error(1, 6, data);
		new_elem->elem = data->args[i];
		new_elem->prev = NULL;
		new_elem->next = NULL;
		add_elem_end_stack(&data->stack_a, new_elem);
		i++;
	}
	return (0);
}

void	add_elem_end_stack(t_stack *stack, t_element *new)
{
	t_element	*aux;

	if (!stack->start)
		stack->start = new;
	else if (stack->size == 1)
	{
		stack->start->next = new;
		new->prev = stack->start;
	}
	else
	{
		aux = stack->start;
		while (aux->next)
		{
			aux = aux->next;
		}
		new->prev = aux;
		aux->next = new;
	}
	stack->size++;
}

void	add_elem_start_stack(t_stack *stack, t_element *new)
{
	t_element	*aux;

	if (!stack->start)
		stack->start = new;
	else
	{
		aux = stack->start;
		aux->prev = new;
		stack->start = new;
		new->next = aux;
		new->prev = NULL;
	}
	stack->size++;
}

t_element	*remove_first_elem_stack(t_stack *stack)
{
	t_element	*aux;

	if (stack->size == 0)
		return (NULL);
	aux = stack->start;
	if (stack->start->next)
		stack->start = stack->start->next;
	else
		stack->start = NULL;
	aux->next = NULL;
	aux->prev = NULL;
	stack->size--;
	return (aux);
}

t_element	*remove_last_elem_stack(t_stack *stack)
{
	t_element	*aux;

	if (stack->size == 0)
		return (NULL);
	aux = stack->start;
	if (stack->size == 1)
		stack->start = NULL;
	else
	{
		while (aux->next)
			aux = aux->next;
		if (aux->prev)
			aux->prev->next = NULL;
		aux->prev = NULL;
	}
	stack->size--;
	return (aux);
}
