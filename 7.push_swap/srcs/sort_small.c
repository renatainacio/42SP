/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 22:24:57 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/24 03:51:49 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_data *data)
{
	t_element	*start;
	int			min;
	int			max;

	min = find_nth_elem(min_value_a(data), &data->stack_a)->elem;
	max = find_nth_elem(max_value_a(data), &data->stack_a)->elem;
	if (stack_is_sorted(&data->stack_a))
		return ;
	start = data->stack_a.start;
	if (start->elem == min)
	{
		add_move_list(data, rra(data));
		add_move_list(data, sa(data));
	}
	else if (start->next->elem == max)
		add_move_list(data, rra(data));
	else if (start->elem == max && start->next->elem == min)
		add_move_list(data, ra(data));
	else if (start->elem == max)
	{
		add_move_list(data, sa(data));
		add_move_list(data, rra(data));
	}	
	else
		add_move_list(data, sa(data));
}

void	sort_four(t_data *data)
{
	int	min_index;
	int	min;

	min_index = min_value_a(data);
	min = find_nth_elem(min_index, &data->stack_a)->elem;
	if (min_index > data->stack_a.size / 2)
	{
		while (data->stack_a.start->elem != min)
			add_move_list(data, rra(data));
	}
	else
	{
		while (data->stack_a.start->elem != min)
			add_move_list(data, ra(data));
	}
	add_move_list(data, pb(data));
	sort_three(data);
	add_move_list(data, pa(data));
}

void	sort_five(t_data *data)
{
	int	min_index;
	int	min;
	int	i;

	i = 0;
	while (i < 2)
	{
		min_index = min_value_a(data);
		min = find_nth_elem(min_index, &data->stack_a)->elem;
		if (min_index > data->stack_a.size / 2)
		{
			while (data->stack_a.start->elem != min)
				add_move_list(data, rra(data));
		}
		else
		{
			while (data->stack_a.start->elem != min)
				add_move_list(data, ra(data));
		}
		add_move_list(data, pb(data));
		i++;
	}
	sort_three(data);
	add_move_list(data, pa(data));
	add_move_list(data, pa(data));
}

void	sort_small(t_data *data)
{
	if (data->nargs == 2)
		add_move_list(data, sa(data));
	else if (data->nargs == 3)
		sort_three(data);
	else if (data->nargs == 4)
		sort_four(data);
	else if (data->nargs == 5)
		sort_five(data);
}
