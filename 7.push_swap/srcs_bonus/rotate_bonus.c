/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:27:25 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/27 21:22:31 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	rotate(t_stack *stack)
{
	t_element	*aux;

	if (stack->size < 2)
		return ;
	aux = remove_first_elem_stack(stack);
	add_elem_end_stack(stack, aux);
}

char	*ra(t_data *data)
{
	rotate(&data->stack_a);
	return ("ra");
}

char	*rb(t_data *data)
{
	rotate(&data->stack_b);
	return ("rb");
}

char	*rr(t_data *data)
{
	rotate(&data->stack_a);
	rotate(&data->stack_b);
	return ("rr");
}
