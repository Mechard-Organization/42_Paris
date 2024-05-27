/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:38 by mechard           #+#    #+#             */
/*   Updated: 2024/05/27 15:50:33 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	if (game->mlx_ptr)
		mlx_destroy_display(game->mlx_ptr);
	free(game->mlx_ptr);
	free(game);
}

void	close_window(t_game *game)
{
	free_game(game);
	exit(0);
}

void	*open_windows(t_game *game)
{
	game->keycode_prev = 0;
	game->mlx_ptr = mlx_init();
	if (game->mlx_ptr == NULL)
		return (free(game), NULL);
	game->win_ptr = mlx_new_window(game->mlx_ptr, 800, 600, "so_long");
	if (game->win_ptr == NULL)
		return (free(game->mlx_ptr), free(game), NULL);

	mlx_hook(game->win_ptr, 2, 1L << 0, (int (*)())key_press, (void *)game);
	mlx_hook(game->win_ptr, 3, 1L << 1, (int (*)())key_release, (void *)game);
	
	mlx_hook(game->win_ptr, 17, 0, (int (*)())close_window, (void *)game); // Fermer avec la croix
	
	mlx_loop(game->mlx_ptr);
	return (0);
}