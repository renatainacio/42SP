/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_stacks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 19:59:47 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/27 20:15:01 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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

int	stack_is_empty(t_stack *stack)
{
	if (!stack->start)
		return (1);
	else
		return (0);
}
