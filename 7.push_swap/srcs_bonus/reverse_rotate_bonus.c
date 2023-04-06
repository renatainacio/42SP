/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 03:16:19 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/27 21:22:26 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	reverse_rotate(t_stack *stack)
{
	t_element	*aux;

	if (stack->size < 2)
		return ;
	aux = remove_last_elem_stack(stack);
	add_elem_start_stack(stack, aux);
}

char	*rra(t_data *data)
{
	reverse_rotate(&data->stack_a);
	return ("rra");
}

char	*rrb(t_data *data)
{
	reverse_rotate(&data->stack_b);
	return ("rrb");
}

char	*rrr(t_data *data)
{
	reverse_rotate(&data->stack_a);
	reverse_rotate(&data->stack_b);
	return ("rrr");
}
