/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkmap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 19:55:22 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 07:02:44 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_charvalidation(t_game	*game)
{
	while (game->map.mgrid[game->map.mheight])
	{
		game->map.mwidth = 0;
		while (game->map.mgrid[game->map.mheight][game->map.mwidth])
		{
			if (ft_strchr("01CEPX", game->map.mgrid[game->map.mheight]
					[game->map.mwidth]) == 0)
				game->map.charvalidation = -1;
			if (game->map.mgrid[game->map.mheight][game->map.mwidth] == 'C')
				game->map.count_c++;
			if (game->map.mgrid[game->map.mheight][game->map.mwidth] == 'E')
				game->map.count_e++;
			if (game->map.mgrid[game->map.mheight][game->map.mwidth] == 'P')
			{
				game->map.count_p++;
				game->map.iplayer = game->map.mwidth;
				game->map.jplayer = game->map.mheight;
			}
			game->map.mwidth++;
		}
		game->map.mheight++;
	}
	return (0);
}

int	ft_is_rectangular(t_game *game)
{
	int	i;

	i = 0;
	while (game->map.mgrid[i])
	{
		if ((int)ft_strlen(game->map.mgrid[i]) != game->map.mwidth)
			return (-1);
		i++;
	}
	return (0);
}

int	ft_is_surrounded(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map.mgrid[0][i])
	{
		if (game->map.mgrid[0][i++] != '1')
			return (-1);
	}
	j = game->map.mheight - 1;
	i = 0;
	while (game->map.mgrid[j][i])
	{
		if (game->map.mgrid[j][i++] != '1')
			return (-1);
	}
	j = 1;
	while (j < game->map.mheight - 1)
	{
		if (game->map.mgrid[j][0] != '1' ||
			game->map.mgrid[j++][game->map.mwidth - 1] != '1')
			return (-1);
	}
	return (0);
}

int	ft_checkmap(t_game *game)
{
	int	error;

	error = -1;
	ft_charvalidation(game);
	if (game->map.mwidth == 0)
		ft_printf("Map should not be empty.\n");
	else if (game->map.charvalidation == -1)
		ft_printf("Map should have only 0, 1, C, E, P, X characters\n");
	else if (game->map.count_c < 1)
		ft_printf("Map should have at least one collectible.\n");
	else if (game->map.count_e != 1)
		ft_printf("Map should have exactly one exit."
			"This map has %d.\n", game->map.count_e);
	else if (game->map.count_p != 1)
		ft_printf("Map should have exactly one starting position."
			"This map has %d.\n", game->map.count_p);
	else if (ft_is_rectangular(game) == -1)
		ft_printf("Map should be rectangular.\n");
	else if (ft_is_surrounded(game) == -1)
		ft_printf("Map should be surrounded by walls.\n");
	else if (ft_check_valid_path(game) < 0)
		ft_printf("Map does not have a valid path.\n");
	else
		error = 0;
	return (error);
}
