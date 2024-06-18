/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 12:02:35 by mechard           #+#    #+#             */
/*   Updated: 2024/06/18 12:09:39 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_moove(char flag, t_game *game)
{
	if (!flag)
		return;
	else if (flag == 'w')
		game->player_y -= 8;
	else if (flag == 's')
		game->player_y += 8;
	else if (flag == 'a')
		game->player_x -= 8;
	else if (flag == 'd')
		game->player_x += 8;
	game->step++;
	ft_printf("\rLe nombre de pas est de %i", game->step);
}

void	move_player(int keycode, t_game *game)
{
	if ((keycode == XK_Up || keycode == XK_w) && game->map[(game->player_y - 8)
			/ 64][game->player_x / 64] != '0')
		ft_moove('w', game);
	if ((keycode == XK_Down || keycode == XK_s) && game->map[(game->player_y
				+ 64) / 64][game->player_x / 64] != '0')
		ft_moove('s', game);
	if ((keycode == XK_Left || keycode == XK_a) && game->map[game->player_y
			/ 64][(game->player_x - 8) / 64] != '0')
		ft_moove('a', game);
	if ((keycode == XK_Right || keycode == XK_d) && game->map[game->player_y
			/ 64][(game->player_x + 64) / 64] != '0')
		ft_moove('d', game);
}
