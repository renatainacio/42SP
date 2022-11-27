/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_game_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:12:55 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 02:35:43 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_freegrid(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.mgrid[i])
		free (game->map.mgrid[i++]);
	free (game->map.mgrid);
}

void	**ft_free(void **array, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (NULL);
}

int	ft_free_dfs(t_game *game)
{
	ft_free((void **)game->map.parent, game->map.mheight);
	ft_free((void **)game->map.visited, game->map.mheight);
	return (0);
}

int	ft_end_game(t_game game, int breakpoint)
{
	ft_freegrid(&game);
	if (breakpoint == 0)
		return (0);
	ft_destroy_img(&game);
	ft_destroy_img_coin(&game);
	if (breakpoint == 1)
		return (0);
	if (breakpoint == 2)
	{
		mlx_destroy_display(game.mlx_ptr);
		free(game.mlx_ptr);
	}
	return (0);
}

int	ft_close_window(t_game *game)
{
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	game->win_ptr = NULL;
	ft_end_game(*game, 2);
	exit(0);
}
