/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 15:55:35 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 03:58:04 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.nargs = argc - 1;
	if (init(&data) || check_args(argv, &data))
		return (1);
	if (!ft_strncmp(argv[1], "Error\n", 6))
		return (1);
	build_stacks(&data);
	read_push_swap_instructions(&data);
	if (stack_is_sorted(&data.stack_a) && stack_is_empty(&data.stack_b))
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	free_all(&data);
}

void	read_push_swap_instructions(t_data *data)
{
	while (1)
	{
		get_next_line(0, data);
		if (data->next_line == NULL)
			break ;
		else if (apply_operations(data, data->next_line,
				ft_strlen(data->next_line)))
		{
			ft_printf("Error\n");
			free(data->next_line);
			free_all(data);
			exit (1);
		}
		free(data->next_line);
	}
}

int	apply_operations(t_data *data, char *operation, int len)
{
	if (!ft_strncmp(operation, "pa\n", len))
		pa(data);
	else if (!ft_strncmp(operation, "pb\n", len))
		pb(data);
	else if (!ft_strncmp(operation, "sa\n", len))
		sa(data);
	else if (!ft_strncmp(operation, "sb\n", len))
		sb(data);
	else if (!ft_strncmp(operation, "ss\n", len))
		ss(data);
	else if (!ft_strncmp(operation, "ra\n", len))
		ra(data);
	else if (!ft_strncmp(operation, "rb\n", len))
		rb(data);
	else if (!ft_strncmp(operation, "rr\n", len))
		rr(data);
	else if (!ft_strncmp(operation, "rra\n", len))
		rra(data);
	else if (!ft_strncmp(operation, "rrb\n", len))
		rrb(data);
	else if (!ft_strncmp(operation, "rrr\n", len))
		rrr(data);
	else
		return (1);
	return (0);
}
