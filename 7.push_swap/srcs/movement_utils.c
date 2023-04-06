/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 13:25:22 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 15:33:12 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_element	*find_nth_elem(int n, t_stack *stack)
{
	t_element	*aux;
	int			i;

	i = 0;
	aux = stack->start;
	while (i < n)
	{
		aux = aux->next;
		i++;
	}
	return (aux);
}

int	find_position_aux(int *comp, t_data *data, int *i, int *min_max)
{
	if (comp[0] > find_nth_elem(min_max[1], &data->stack_a)->elem)
	{
		*i = min_max[1] + 1;
		return (1);
	}
	else if (comp[0] < find_nth_elem(min_max[0], &data->stack_a)->elem)
	{
		*i = min_max[0];
		return (1);
	}
	else if (comp[0] > comp[1] && comp[0] < comp[2])
		return (1);
	else
		return (0);
}

int	find_position(t_element *elem_b, t_data *data)
{
	t_element	*aux_a;
	int			found;
	int			i;
	int			comp[3];
	int			min_max[2];

	min_max[0] = min_value_a(data);
	min_max[1] = max_value_a(data);
	aux_a = data->stack_a.start;
	found = 0;
	i = 1;
	while (aux_a->next)
	{
		comp[0] = elem_b->elem;
		comp[1] = aux_a->elem;
		comp[2] = aux_a->next->elem;
		found = find_position_aux(comp, data, &i, min_max);
		if (found == 1)
			break ;
		aux_a = aux_a->next;
		i++;
	}
	if (found == 0)
		i = 0;
	return (i);
}

int	aux_total_movements(int pos_a, int pos_b, int num, t_data *data)
{
	int	reverse_a;
	int	reverse_b;

	reverse_a = data->stack_a.size - pos_a;
	reverse_b = data->stack_b.size - pos_b;
	if (num == 1)
		data->min_moves = reverse_a;
	else if (num == 2)
		data->min_moves = reverse_b;
	else if (num == 3)
			data->min_moves = reverse_a + pos_b;
	else if (num == 4)
			data->min_moves = pos_a + reverse_b;
	else if (num == 5)
			data->min_moves = pos_a;
	else if (num == 6)
			data->min_moves = pos_b;
	return (num);
}

int	calculate_total_movements(int pos_a, int pos_b, t_data *data)
{
	int	reverse_a;
	int	reverse_b;

	reverse_a = data->stack_a.size - pos_a;
	reverse_b = data->stack_b.size - pos_b;
	if (reverse_a > reverse_b)
		data->next_move = aux_total_movements(pos_a, pos_b, 1, data);
	else
		data->next_move = aux_total_movements(pos_a, pos_b, 2, data);
	if (reverse_a + pos_b < data->min_moves)
		data->next_move = aux_total_movements(pos_a, pos_b, 3, data);
	if (pos_a + reverse_b < data->min_moves)
		data->next_move = aux_total_movements(pos_a, pos_b, 4, data);
	if (pos_a > pos_b && pos_a < data->min_moves)
		data->next_move = aux_total_movements(pos_a, pos_b, 5, data);
	else if (pos_a < pos_b && pos_b < data->min_moves)
		data->next_move = aux_total_movements(pos_a, pos_b, 6, data);
	return (data->min_moves);
}
