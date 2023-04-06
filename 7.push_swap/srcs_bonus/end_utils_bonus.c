/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/18 02:18:18 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 05:16:18 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	free_all(t_data *data)
{
	free(data->args);
	if (data->stack_a.start)
		free_stack(data->stack_a.start);
	if (data->stack_b.start)
		free_stack(data->stack_b.start);
}

void	free_stack(t_element *elem)
{
	if (elem->next)
		free_stack(elem->next);
	free (elem);
}
