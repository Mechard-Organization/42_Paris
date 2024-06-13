/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:04:44 by mechard           #+#    #+#             */
/*   Updated: 2024/06/13 15:53:58 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_player(int keycode, t_game *game)
{
	if ((keycode == XK_Up || keycode == XK_w) && game->map[(game->Player_y - 8)
			/ 64][game->Player_x / 64] != '0')
	{
		game->Player_y -= 8;
		game->step++;
	}
	if ((keycode == XK_Down || keycode == XK_s) && game->map[(game->Player_y
				+ 64) / 64][game->Player_x / 64] != '0')
	{
		game->Player_y += 8;
		game->step++;
	}
	if ((keycode == XK_Left || keycode == XK_a) && game->map[game->Player_y
			/ 64][(game->Player_x - 8) / 64] != '0')
	{
		game->Player_x -= 8;
		game->step++;
	}
	if ((keycode == XK_Right || keycode == XK_d) && game->map[game->Player_y
			/ 64][(game->Player_x + 64) / 64] != '0')
	{
		game->Player_x += 8;
		game->step++;
	}
}

void	ft_collect(t_game *game)
{
	int	taille;

	taille = 64;
	if (game->map[game->Player_y / 64][game->Player_x / 64] == 'C'
		&& game->Player_y % 64 == 0 && game->Player_x % 64 == 0)
	{
		game->map[game->Player_y / 64][game->Player_x / 64] = '1';
		game->collectibles++;
	}
	if (game->collectibles == game->nb_collectibles)
	{
		mlx_destroy_image(game->mlx_ptr, game->exi);
		game->exi = mlx_xpm_file_to_image(game->mlx_ptr, "sprites/fin.xpm",
				&taille, &taille);
		if (!game->exi)
		{
			ft_printf(ERROR_COL);
			return ;
		}
		game->exit = 1;
	}
}

void	ft_finish(t_game *game)
{
	if (game->map[game->Player_y / 64][game->Player_x / 64] == 'E'
		&& game->Player_y % 64 == 0 && game->Player_x % 64 == 0
		&& game->collectibles == game->nb_collectibles)
	{
		ft_printf(SUCCESS);
		close_window(game);
	}
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == XK_Control_L)
		game->keycode_prev = 1;
	if (keycode == XK_Escape)
		close_window(game);
	if ((keycode == XK_d || keycode == XK_c) && game->keycode_prev == 1)
		close_window(game);
	move_player(keycode, game);
	ft_collect(game);
	ft_printf("Le nombre de pas est de %i\n", game->step);
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_Control_L)
		game->keycode_prev = 0;
	return (0);
}
