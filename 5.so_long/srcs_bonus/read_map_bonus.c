/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 17:15:53 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 02:35:51 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_maplen(char *mapfile)
{
	int		maplen;
	int		read_result;
	char	buf;
	int		fd;

	fd = open(mapfile, O_RDONLY);
	if (fd < 0)
		return (-1);
	maplen = 0;
	read_result = 1;
	while (read_result != 0)
	{
		read_result = read(fd, &buf, 1);
		if (read_result == -1)
			return (0);
		maplen++;
	}
	close(fd);
	maplen--;
	return (maplen);
}	

int	ft_read_map(t_game *game)
{
	int		read_result;
	char	*maparray;
	int		maplen;
	int		fd;

	ft_set_map_variables(game);
	maplen = ft_maplen(game->map.mfile);
	if (maplen == -1)
		return (-1);
	fd = open(game->map.mfile, O_RDONLY);
	maparray = malloc((maplen + 1) * sizeof(char));
	if (!maparray)
		return (0);
	read_result = 1;
	read_result = read(fd, maparray, maplen);
	if (read_result == -1)
	{
		free(maparray);
		return (-1);
	}
	maparray[maplen] = '\0';
	game->map.mgrid = ft_split(maparray, '\n');
	close(fd);
	free(maparray);
	return (0);
}

void	ft_set_map_variables(t_game *game)
{
	game->map.mheight = 0;
	game->map.mwidth = 0;
	game->map.count_c = 0;
	game->map.count_p = 0;
	game->map.count_e = 0;
	game->map.charvalidation = 0;
}
