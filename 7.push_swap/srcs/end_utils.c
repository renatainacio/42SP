/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:18:18 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/27 16:37:09 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_all(t_data *data)
{
	free(data->args);
	if (data->stack_a.start)
		free_stack(data->stack_a.start);
	if (data->stack_b.start)
		free_stack(data->stack_b.start);
	if (data->stack_aux.start)
		free_stack(data->stack_aux.start);
	if (data->moves_list.start)
		free_moves_list(data->moves_list.start);
}

void	free_stack(t_element *elem)
{
	if (elem->next)
		free_stack(elem->next);
	free (elem);
}

void	free_moves_list(t_move *elem)
{
	if (elem->next)
		free_moves_list(elem->next);
	free (elem);
}
