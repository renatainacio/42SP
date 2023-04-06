/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 23:58:35 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/27 21:22:22 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push(t_stack *s1, t_stack *s2)
{
	t_element	*first_elem;

	if (s2->size == 0)
		return ;
	first_elem = remove_first_elem_stack(s2);
	add_elem_start_stack(s1, first_elem);
}

char	*pa(t_data *data)
{
	push(&data->stack_a, &data->stack_b);
	return ("pa");
}

char	*pb(t_data *data)
{
	push(&data->stack_b, &data->stack_a);
	return ("pb");
}
