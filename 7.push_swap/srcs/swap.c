/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:57:56 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/24 02:31:52 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_first_two(t_stack *stack)
{
	t_element	*aux;

	if (stack->size < 2)
		return ;
	aux = stack->start->next;
	stack->start->next = aux->next;
	stack->start->prev = aux;
	aux->next = stack->start;
	aux->prev = NULL;
	if (stack->start->next != NULL)
		stack->start->next->prev = stack->start;
	stack->start = aux;
}

char	*sa(t_data *data)
{
	swap_first_two(&data->stack_a);
	return ("sa");
}

char	*sb(t_data *data)
{
	swap_first_two(&data->stack_b);
	return ("sb");
}

char	*ss(t_data *data)
{
	swap_first_two(&data->stack_a);
	swap_first_two(&data->stack_b);
	return ("ss");
}
