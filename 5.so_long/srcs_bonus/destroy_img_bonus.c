/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_img_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:15:23 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 07:42:26 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_destroy_img(t_game *game)
{
	if (game->map.exit_open_img)
		mlx_destroy_image(game->mlx_ptr, game->map.exit_open_img);
	if (game->map.exit_closed_img)
		mlx_destroy_image(game->mlx_ptr, game->map.exit_closed_img);
	if (game->map.grass_img)
		mlx_destroy_image(game->mlx_ptr, game->map.grass_img);
	if (game->map.char_back_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_back_img);
	if (game->map.char_front_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_front_img);
	if (game->map.char_right_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_right_img);
	if (game->map.char_left_img)
		mlx_destroy_image(game->mlx_ptr, game->map.char_left_img);
	if (game->map.wall_img)
		mlx_destroy_image(game->mlx_ptr, game->map.wall_img);
	if (game->map.first_wall_img)
		mlx_destroy_image(game->mlx_ptr, game->map.first_wall_img);
	if (game->map.enemy_img)
		mlx_destroy_image(game->mlx_ptr, game->map.enemy_img);
	if (game->map.rip_img)
		mlx_destroy_image(game->mlx_ptr, game->map.rip_img);
}

void	ft_destroy_img_coin(t_game *game)
{
	int	i_coin;

	i_coin = 0;
	while (i_coin < 16)
	{
		if (game->map.coin_img[i_coin])
			mlx_destroy_image(game->mlx_ptr, game->map.coin_img[i_coin]);
		i_coin++;
	}
}
