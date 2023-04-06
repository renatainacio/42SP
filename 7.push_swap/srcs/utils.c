/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 03:57:56 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 20:41:06 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_if_keep_in_a(t_data *data, int elem_ref, int aux)
{
	if ((data->stack_a.start->elem < elem_ref && aux == 0)
		|| (data->stack_a.start->elem > elem_ref
			&& data->stack_a.start->elem < data->head.head_elem))
		return (1);
	else
		return (0);
}

int	check_if_swap_a(t_data *data, int elem_ref, int aux, int i)
{
	if (data->stack_a.start->next->elem > data->stack_a.start->elem
		&& aux == 1 && data->stack_a.start->next->elem > elem_ref
		&& data->stack_a.start->next->elem < data->head.head_elem
		&& i != data->head.head_index - 1)
		add_move_list(data, sa(data));
	else
		return (0);
	return (1);
}

int	check_if_swap_a_end(t_data *data, int elem_ref, int aux)
{
	if (data->stack_a.start->next->elem < data->stack_a.start->elem
		&& aux == 1 && data->stack_a.start->next->elem > elem_ref)
		add_move_list(data, sa(data));
	else
		return (0);
	return (1);
}

int	move_elem_before_head(t_data *data, int elem_ref, int *aux, int i)
{
	if (check_if_keep_in_a(data, elem_ref, *aux))
	{
		check_if_swap_a(data, elem_ref, *aux, i);
		elem_ref = data->stack_a.start->elem;
		add_move_list(data, ra(data));
		*aux = 1;
	}
	else
		add_move_list(data, pb(data));
	return (elem_ref);
}

int	move_elem_after_head(t_data *data, int elem_ref, int aux)
{
	if (data->stack_a.start->elem > elem_ref)
	{
		check_if_swap_a_end(data, elem_ref, aux);
		elem_ref = data->stack_a.start->elem;
		add_move_list(data, ra(data));
	}
	else
		add_move_list(data, pb(data));
	return (elem_ref);
}
