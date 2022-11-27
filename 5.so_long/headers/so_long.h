/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/09 02:09:24 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 06:23:05 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>

# define BUFFER_SIZE 14
# define TILE_SIZE 64

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}	t_img;

typedef struct s_map
{
	char	*mpath;
	char	*mfile;
	char	**mgrid;
	int		mheight;
	int		mwidth;
	int		count_c;
	int		count_e;
	int		count_p;
	int		charvalidation;
	int		iplayer;
	int		jplayer;
	int		**visited;
	int		**parent;
	int		c_dfs;
	int		e_dfs;
	void	*exit_open_img;
	void	*exit_closed_img;
	void	*grass_img;
	void	*char_back_img;
	void	*char_front_img;
	void	*char_right_img;
	void	*char_left_img;
	void	**coin_img[16];
	void	*wall_img;
	void	*first_wall_img;
	int		x_tile;
	int		y_tile;
}	t_map;

typedef struct s_game
{
	void	*mlx_ptr;
	void	*win_ptr;
	int		win_height;
	int		win_width;
	int		move_count;
	int		collected;
	char	char_direction;
	int		count_loop;
	t_img	img;
	t_map	map;
}	t_game;

void	**ft_free(void **array, int count);

int		ft_check_valid_path(t_game	*game);

int		ft_checkmap(t_game *game);

int		ft_is_surrounded(t_game *game);

int		ft_is_rectangular(t_game *game);

int		ft_charvalidation(t_game	*game);

void	ft_set_map_variables(t_game *game);

int		ft_read_map(t_game *game);

int		ft_maplen(char *mapfile);

void	move_backwards(t_game *game, int *i, int *j, int parent);

void	ft_dfs_walls(t_game *game);

int		ft_dfs_setup(t_game *game);

int		ft_end_game(t_game game, int breakpoint);

int		ft_free_dfs(t_game *game);

int		ft_move_forward(t_game *game, int *i, int *j);

int		stop(t_game *game);

int		handle_keypress(int keysym, t_game *game);

void	img_pix_put(t_img *img, int x, int y, int color);

int		render(t_game *game);

int		generate_img(t_game	*game);

int		generate_img_coin(t_game *game);

void	ft_aux_put_image(t_game *game, int i, int j);

void	ft_free_img(t_game *game);

void	ft_destroy_img(t_game *game);

int		ft_input_validation(int argc, char *argv);

void	ft_freegrid(t_game *game);

int		ft_close_window(t_game *game);

void	ft_move_down(t_game *game);

void	ft_move_up(t_game *game);

void	ft_move_right(t_game *game);

void	ft_move_left(t_game *game);

void	render_player(t_game *game);

void	ft_destroy_img_coin(t_game *game);

void	initialize_game_variables(t_game *game);

int		open_window(t_game *game);

void	move_conditionals(t_game *game, char tile);

#endif