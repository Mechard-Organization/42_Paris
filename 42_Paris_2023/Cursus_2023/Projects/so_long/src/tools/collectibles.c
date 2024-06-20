/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectibles.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:53:56 by mechard           #+#    #+#             */
/*   Updated: 2024/06/20 14:11:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_collect_up(t_game *game)
{
	if (game->player_x % 64 == 0)
	{
		game->map[game->player_y / 64][game->player_x / 64] = '1';
		game->collectibles++;
	}
	else if (game->map[(game->player_y - 8) / 64][(game->player_x / 64)
		+ 1] != 'C')
	{
		game->map[game->player_y / 64][(game->player_x / 64) + 1] = '1';
		game->collectibles++;
	}
}

void	ft_collect_down(t_game *game)
{
	if (game->player_x % 64 == 0)
	{
		game->map[game->player_y / 64][game->player_x / 64] = '1';
		game->collectibles++;
	}
	else if (game->map[(game->player_y + 64) / 64][(game->player_x / 64)
		+ 1] != '0')
	{
		game->map[game->player_y / 64][(game->player_x / 64)
		+ 1] = '1';
		game->collectibles++;
	}
}

void	ft_collect_left(t_game *game)
{
	if (game->player_y % 64 == 0)
	{
		game->map[game->player_y / 64][game->player_x / 64] = '1';
		game->collectibles++;
	}
	else if (game->map[(game->player_y / 64) + 1][(game->player_x - 8)
		/ 64] != '0')
	{
		game->map[(game->player_y / 64) + 1][game->player_x / 64] = '1';
		game->collectibles++;
	}
}

void	ft_collect_right(t_game *game)
{
	if (game->player_y % 64 == 0)
	{
		game->map[game->player_y / 64][game->player_x / 64] = '1';
		game->collectibles++;
	}
	else if (game->map[(game->player_y / 64) + 1][(game->player_x + 64)
		/ 64] != '0')
	{
		game->map[(game->player_y / 64) + 1][game->player_x / 64] = '1';
		game->collectibles++;
	}
}

void	ft_collect(t_game *game)
{
	int taille;

	taille = 64;
	if (game->map[(game->player_y - 8) / 64][game->player_x / 64] != 'C')
		ft_collect_up(game);
	if (game->map[(game->player_y + 64) / 64][game->player_x / 64] != 'C')
		ft_collect_down(game);
	if (game->map[game->player_y / 64][(game->player_x - 8) / 64] != 'C')
		ft_collect_left(game);
	if (game->map[game->player_y / 64][(game->player_x + 64) / 64] != 'C')
		ft_collect_right(game);
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