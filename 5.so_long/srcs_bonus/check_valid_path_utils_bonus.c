/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valid_path_utils.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:12:47 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 03:10:01 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_dfs_setup(t_game *game)
{
	int	j;

	game->map.c_dfs = 0;
	game->map.e_dfs = 0;
	game->map.visited = (int **) malloc (sizeof(int *) * (game->map.mheight));
	if (game->map.visited == NULL)
		return (-1);
	game->map.parent = (int **) malloc (sizeof(int *) * (game->map.mheight));
	if (!(game->map.parent) || !(game->map.visited))
		return (ft_free_dfs(game) - 1);
	j = 0;
	while (j < game->map.mheight)
	{
		game->map.visited[j] = calloc(game->map.mwidth, sizeof(int));
		if (!game->map.visited[j])
		{
			ft_free((void **)game->map.visited, game->map.mheight);
			return (-1);
		}
		game->map.parent[j] = calloc(game->map.mwidth, sizeof(int));
		if (!game->map.parent[j])
			return (ft_free_dfs(game) - 1);
		j++;
	}	
	return (0);
}

void	ft_dfs_walls(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < game->map.mheight)
	{
		i = 0;
		while (i < game->map.mwidth)
		{
			if (game->map.mgrid[j][i] == '1'
				|| game->map.mgrid[j][i] == 'X')
				game->map.visited[j][i] = 2;
			i++;
		}
		j++;
	}
}

int	stop(t_game *game)
{
	int	stop;
	int	i;
	int	j;

	i = game->map.iplayer;
	j = game->map.jplayer;
	stop = ((game->map.visited[j + 1][i] == 2
				&& game->map.visited[j - 1][i] == 2
				&& game->map.visited[j][i + 1] == 2
				&& game->map.visited[j][i - 1] == 2)
			|| (game->map.c_dfs == game->map.count_c
				&& game->map.e_dfs == 1));
	return (stop);
}

int	ft_move_forward(t_game *game, int *i, int *j)
{
	if (game->map.visited[*j + 1][*i] == 0)
	{
		game->map.parent[*j + 1][*i] = *j * game->map.mwidth + *i;
		*j = *j + 1;
	}
	else if (game->map.visited[*j][*i + 1] == 0)
	{
		game->map.parent[*j][*i + 1] = *j * game->map.mwidth + *i;
		*i = *i + 1;
	}
	else if (game->map.visited[*j - 1][*i] == 0)
	{
		game->map.parent[*j - 1][*i] = *j * game->map.mwidth + *i;
		*j = *j - 1;
	}
	else if (game->map.visited[*j][*i - 1] == 0)
	{
		game->map.parent[*j][*i - 1] = *j * game->map.mwidth + *i;
		*i = *i - 1;
	}
	else
		return (1);
	return (0);
}

void	move_backwards(t_game *game, int *i, int *j, int parent)
{
	*i = parent % game->map.mwidth;
	*j = parent / game->map.mwidth;
}
