/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:04:44 by mechard           #+#    #+#             */
/*   Updated: 2024/06/18 12:02:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect(t_game *game)
{
	int	taille;

	taille = 64;
	if (game->map[game->player_y / 64][game->player_x / 64] == 'C'
		&& game->player_y % 64 == 0 && game->player_x % 64 == 0)
	{
		game->map[game->player_y / 64][game->player_x / 64] = '1';
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
	if (game->map[game->player_y / 64][game->player_x / 64] == 'E'
		&& game->player_y % 64 == 0 && game->player_x % 64 == 0
		&& game->collectibles == game->nb_collectibles)
	{
		ft_printf(SUCCESS, game->step);
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
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == XK_Control_L)
		game->keycode_prev = 0;
	return (0);
}
