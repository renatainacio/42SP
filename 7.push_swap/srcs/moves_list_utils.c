/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 05:36:28 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 05:36:51 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_move_list(t_data *data, char *movement)
{
	t_move	*aux;
	t_move	*new_move;

	new_move = (t_move *)malloc(sizeof(t_move));
	if (!new_move)
		return ;
	new_move->move = movement;
	new_move->next = NULL;
	if (!data->moves_list.start)
		data->moves_list.start = new_move;
	else
	{
		aux = data->moves_list.start;
		while (aux->next)
			aux = aux->next;
		aux->next = new_move;
		aux->next->next = NULL;
	}
}

void	print_moves(t_data data)
{
	t_move	*aux;

	aux = data.moves_list.start;
	while (aux)
	{
		ft_printf("%s\n", aux->move);
		aux = aux->next;
	}
}
