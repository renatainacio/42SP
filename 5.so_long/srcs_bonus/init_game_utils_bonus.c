/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 22:40:33 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 03:49:18 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_input_validation(int argc, char *map_path)
{
	if (argc != 2)
		return (ft_printf("Invalid number of arguments"
				"(you should input exactly one).\n"));
	else if (ft_strncmp(map_path + ft_strlen(map_path) - 4, ".ber", 4) != 0)
		return (write(1, "The map file should have .ber extension\n", 40));
	return (0);
}

void	initialize_game_variables(t_game *game)
{
	game->move_count = 0;
	game->collected = 0;
	game->char_direction = 'F';
	game->count_loop = 0;
	game->win_height = TILE_SIZE * game->map.mheight;
	game->win_width = TILE_SIZE * game->map.mwidth;
}

int	open_window(t_game *game)
{
	game->win_ptr = mlx_new_window(game->mlx_ptr, game->win_width,
			game->win_height, "So_Long");
	if (!game->win_ptr)
	{
		ft_printf("Error while opening game window.\n");
		return (-1);
	}
	return (0);
}

int	initializing_mlx(t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
	{
		ft_printf("Error while initializing mlx.\n");
		return (-1);
	}
	return (0);
}
