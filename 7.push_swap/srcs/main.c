/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 22:32:12 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 20:20:35 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_data	data;

	data.nargs = argc - 1;
	if (init(&data) || check_args(argv, &data))
		return (1);
	if (is_sorted(&data, 1))
		return (0);
	build_stacks(&data);
	sort(&data);
	print_moves(data);
	free_all(&data);
}
