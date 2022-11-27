/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:13:02 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 04:01:41 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	main(int argc, char *argv[])
{
	t_game	game;

	if (ft_input_validation(argc, argv[1]) != 0)
		return (0);
	game.map.mfile = argv[1];
	if (ft_read_map(&game) == -1)
		return (ft_printf("Unable to open the informed map file. "
				"Please check if informed path is correct.\n"));
	if (ft_checkmap(&game) < 0)
		return (ft_end_game(game, 0));
	if (initializing_mlx(&game) < 0)
		return (ft_end_game(game, 0));
	generate_img(&game);
	generate_img_coin(&game);
	generate_img_enemy(&game);
	initialize_game_variables(&game);
	if (open_window(&game) != 0)
		ft_end_game(game, 2);
	mlx_key_hook(game.win_ptr, &handle_keypress, &game);
	mlx_hook(game.win_ptr, DestroyNotify, NoEventMask, &ft_close_window, &game);
	mlx_loop_hook(game.mlx_ptr, &render, &game);
	mlx_loop(game.mlx_ptr);
}
