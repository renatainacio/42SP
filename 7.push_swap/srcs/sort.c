/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 00:15:24 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 00:28:28 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_data *data)
{
	indexation(data);
	create_aux(data);
	if (data->nargs <= 5)
		sort_small(data);
	else
	{
		find_head_stack_a(data);
		move_to_b(data);
		move_to_a(data);
		adjust_a(data);
	}
}

void	find_head_stack_a(t_data *data)
{
	t_element	*aux;
	int			i;
	int			*head_possibilities;

	head_possibilities = (int *)malloc(sizeof(int) * data->nargs);
	if (!head_possibilities)
		exit (1);
	aux = data->stack_a.start;
	i = 0;
	while (aux)
	{
		head_possibilities[i] = count_keep_in_a(data, i);
		aux = aux->next;
		i++;
	}
	find_max(head_possibilities, data->nargs, data);
	data->head.head_elem
		= find_nth_elem(data->head.head_index, &data->stack_a)->elem;
	free(head_possibilities);
}

void	move_to_b(t_data *data)
{
	int	elem_ref;
	int	i;
	int	aux;

	i = 0;
	aux = 0;
	elem_ref = data->head.head_elem;
	while (i < data->head.head_index)
	{
		if (check_if_keep_in_a(data, elem_ref, aux))
		{
			check_if_swap_a(data, elem_ref, aux, i);
			elem_ref = data->stack_a.start->elem;
			add_move_list(data, ra(data));
			aux = 1;
		}
		else
			add_move_list(data, pb(data));
		i++;
	}
	if (i++ == data->head.head_index)
		add_move_list(data, ra(data));
	elem_ref = data->head.head_elem;
	while (i++ < data->nargs)
		elem_ref = move_elem_after_head(data, elem_ref, aux);
}

void	move_to_a(t_data *data)
{
	int			b;
	int			a;
	int			total_movements;
	t_element	*elem_b;

	while (data->stack_b.size)
	{
		b = element_to_move(data);
		elem_b = find_nth_elem(b, &data->stack_b);
		a = find_position(elem_b, data);
		total_movements = calculate_total_movements(a, b, data);
		if (data->next_move == 5)
			move_to_a_aux(b, a, data);
		else if (data->next_move == 6)
			move_to_a_aux(a, b, data);
		else if (data->next_move == 1)
			move_i(data->stack_b.size - b, b, data->stack_a.size - a, data);
		else if (data->next_move == 2)
			move_i(data->stack_a.size - a, a, data->stack_b.size - b, data);
		else if (data->next_move == 3)
			move_ii(data->stack_a.size - a, a, b, data);
		else if (data->next_move == 4)
			move_ii(data->stack_b.size - b, b, a, data);
		add_move_list(data, pa(data));
	}
}

void	adjust_a(t_data *data)
{
	int	i;
	int	first;

	i = min_value_a(data);
	first = find_nth_elem(i, &data->stack_a)->elem;
	if (i > data->stack_a.size / 2)
	{
		while (data->stack_a.start->elem != first)
			add_move_list(data, rra(data));
	}
	else
	{
		while (data->stack_a.start->elem != first)
			add_move_list(data, ra(data));
	}
}
