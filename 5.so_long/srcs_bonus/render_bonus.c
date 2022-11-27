/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:13:11 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 08:07:57 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	generate_img(t_game	*game)
{
	game->map.grass_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/grass.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/wall.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.first_wall_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/first_wall.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.exit_open_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/trapdoor_open.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.exit_closed_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/trapdoor.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.char_back_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char_back.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.char_front_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char_front.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.char_right_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char_right.xpm", &game->map.x_tile, &game->map.y_tile);
	game->map.char_left_img = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/char_left.xpm", &game->map.x_tile, &game->map.y_tile);
	if (!game->map.grass_img || !game->map.exit_closed_img
		|| !game->map.wall_img || !game->map.exit_open_img
		|| !game->map.char_back_img || !game->map.char_front_img
		|| !game->map.char_right_img || !game->map.char_left_img
		|| !game->map.first_wall_img)
		return (ft_printf("Error while creating image.\n"));
	return (0);
}

int	generate_img_coin(t_game *game)
{
	int		i;
	char	*img_path;
	char	*aux;
	char	*a;

	game->map.coin_img[0] = mlx_xpm_file_to_image(game->mlx_ptr,
			"./images/coin.xpm", &game->map.x_tile, &game->map.y_tile);
	i = 1;
	while (i < 16)
	{
		a = ft_itoa(i + 1);
		aux = ft_strjoin("./images/coin", a);
		img_path = ft_strjoin(aux, ".xpm");
		game->map.coin_img[i] = mlx_xpm_file_to_image(game->mlx_ptr,
				img_path, &game->map.x_tile, &game->map.y_tile);
		if (!game->map.coin_img[i])
			return (ft_printf("Error while creating image.\n"));
		i++;
		free(img_path);
		free(a);
		free(aux);
	}
	return (0);
}

int	render(t_game *game)
{
	int		i;
	int		j;
	char	*moves;

	j = 0;
	if (!game->win_ptr)
		return (1);
	while (j < game->map.mheight)
	{
		i = 0;
		while (i < game->map.mwidth)
			ft_aux_put_image(game, i++, j);
		j++;
	}
	render_player(game);
	if (game->char_direction != 'D')
	{
		mlx_string_put(game->mlx_ptr, game->win_ptr, 15, 30, WHITE, "moves:");
		moves = ft_itoa(game->move_count);
		mlx_string_put(game->mlx_ptr, game->win_ptr, 25, 42, WHITE, moves);
		free(moves);
	}
	else
		mlx_string_put(game->mlx_ptr, game->win_ptr, 17, 35, WHITE, "LOSER");
	return (0);
}

void	ft_aux_put_image(t_game *game, int i, int j)
{
	void	*img;

	if (game->count_loop > PACE * 16)
		game->count_loop = 0;
	if (i == 0 && j == 0)
		img = game->map.first_wall_img;
	else if (game->map.mgrid[j][i] == '1')
		img = game->map.wall_img;
	else if (game->map.mgrid[j][i] == 'C')
		img = game->map.coin_img[game->count_loop / PACE];
	else if (game->map.mgrid[j][i] == 'X')
		img = game->map.enemy_img;
	else if (game->map.mgrid[j][i] == 'E')
	{
		if (game->collected != game->map.count_c)
			img = game->map.exit_closed_img;
		else
			img = game->map.exit_open_img;
	}
	else
		img = game->map.grass_img;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, TILE_SIZE * i, TILE_SIZE * j);
	game->count_loop++;
}

void	render_player(t_game *game)
{
	void	*img;

	if (game->char_direction == 'F')
		img = game->map.char_front_img;
	if (game->char_direction == 'B')
		img = game->map.char_back_img;
	if (game->char_direction == 'R')
		img = game->map.char_right_img;
	if (game->char_direction == 'L')
		img = game->map.char_left_img;
	if (game->char_direction == 'D')
		img = game->map.rip_img;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img, TILE_SIZE * game->map.iplayer, TILE_SIZE * game->map.jplayer);
}
