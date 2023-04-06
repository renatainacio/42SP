/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element_to_move.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 20:05:04 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 20:05:13 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	element_to_move(t_data *data)
{
	t_element	*elem_b;
	int			*ra_moves;
	int			*n_moves;
	int			n_rb;
	int			min;

	ra_moves = (int *)malloc(sizeof(int) * data->stack_b.size);
	if (!ra_moves)
		exit(1);
	n_moves = (int *)malloc(sizeof(int) * data->stack_b.size);
	if (!n_moves)
		exit (1);
	elem_b = data->stack_b.start;
	n_rb = 0;
	while (n_rb < data->stack_b.size)
	{
		ra_moves[n_rb] = find_position(elem_b, data);
		n_moves[n_rb] = calculate_total_movements(ra_moves[n_rb], n_rb, data);
		n_rb++;
		elem_b = elem_b->next;
	}
	min = find_min(n_moves, data->stack_b.size);
	free(ra_moves);
	free(n_moves);
	return (min);
}
