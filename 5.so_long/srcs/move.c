/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 05:18:55 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 03:08:18 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_move_down(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer + 1][game->map.iplayer];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'F';
		game->map.jplayer++;
	}
	move_conditionals(game, tile);
}

void	ft_move_up(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer - 1][game->map.iplayer];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'B';
		game->map.jplayer--;
	}
	move_conditionals(game, tile);
}

void	ft_move_right(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer][game->map.iplayer + 1];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'R';
		game->map.iplayer++;
	}
	move_conditionals(game, tile);
}

void	ft_move_left(t_game *game)
{
	char	tile;

	tile = game->map.mgrid[game->map.jplayer][game->map.iplayer - 1];
	if (tile != '1')
	{
		game->move_count++;
		game->char_direction = 'L';
		game->map.iplayer--;
	}
	move_conditionals(game, tile);
}

void	move_conditionals(t_game *game, char tile)
{
	if (tile == 'C')
	{
		game->map.mgrid[game->map.jplayer][game->map.iplayer] = '0';
		game->collected++;
	}
	if (tile == 'E' && game->collected == game->map.count_c)
	{
		ft_printf("You won! Number of movements: %d\n", game->move_count);
		ft_close_window(game);
	}
	ft_printf("moves: %d\r", game->move_count);
}
