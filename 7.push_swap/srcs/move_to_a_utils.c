/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_a_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 00:16:13 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 00:30:38 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_movement(t_data *data, int id)
{
	if ((data->next_move == 5 || data->next_move == 6) && id == 1)
		add_move_list(data, rr(data));
	else if ((data->next_move == 5 && id == 2)
		|| (data->next_move == 4 && id == 2))
		add_move_list(data, ra(data));
	else if ((data->next_move == 6 && id == 2)
		|| (data->next_move == 3 && id == 2))
		add_move_list(data, rb(data));
	else if ((data->next_move == 1
			|| data->next_move == 2) && id == 1)
		add_move_list(data, rrr(data));
	else if ((data->next_move == 1 && id == 2)
		|| (data->next_move == 3 && id == 1))
		add_move_list(data, rra(data));
	else if ((data->next_move == 2 && id == 2)
		|| (data->next_move == 4 && id == 1))
		add_move_list(data, rrb(data));
}

void	move_to_a_aux(int first, int last, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < first)
		execute_movement(data, 1);
	i--;
	while (i++ < last)
		execute_movement(data, 2);
}

void	move_i(int first, int sec, int last, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < first && sec != 0)
		execute_movement(data, 1);
	i--;
	while (i++ < last)
		execute_movement(data, 2);
}

void	move_ii(int first, int sec, int last, t_data *data)
{
	int	i;

	i = 0;
	while (i++ < first && sec != 0)
		execute_movement(data, 1);
	i = 0;
	while (i++ < last)
		execute_movement(data, 2);
}
