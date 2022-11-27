/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 03:14:58 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 08:10:41 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	generate_img_enemy(t_game *game)
{
	game->map.enemy_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/enemy.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.rip_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/rip.xpm", &game->map.x_tile, &game->map.y_tile);
	if (!game->map.enemy_img || !game->map.rip_img)
		return (ft_printf("Error while creating image.\n"));
	return (0);
}
