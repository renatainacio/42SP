/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 02:56:51 by rinacio           #+#    #+#             */
/*   Updated: 2022/11/12 07:50:30 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape || keysym == XK_q)
		ft_close_window(game);
	if (game->char_direction != 'D')
	{
		if (keysym == XK_s || keysym == XK_Down)
			ft_move_down(game);
		if (keysym == XK_w || keysym == XK_Up)
			ft_move_up(game);
		if (keysym == XK_d || keysym == XK_Right)
			ft_move_right(game);
		if (keysym == XK_a || keysym == XK_Left)
			ft_move_left(game);
	}
	return (0);
}
