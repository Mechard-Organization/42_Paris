/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:38 by mechard           #+#    #+#             */
/*   Updated: 2024/05/20 12:15:18 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		close_window(void *param)
{
	t_game *game;
	
	game = (t_game *)param;
	game->is_running = 0;
	return (0);
}

int		key_press(int keycode, void *param)
{
	// printf("keycode = %d\n", keycode);
    if (keycode == 65307 || keycode == 99)
		close_window(param);
    return (0);
}	

// int		create_map(char **str)
// {
	
// }

void		*open_windows()
{
	t_game game;
	
	game.is_running = 1;
	game.mlx_ptr = mlx_init();
	game.win_ptr = mlx_new_window(game.mlx_ptr, 800, 600, "so_long");
	
	printf ("mlx_hook = %d\n", mlx_hook(game.win_ptr, 17, 0, close_window, &game));
	printf ("mlx_hook = %d\n", mlx_hook(game.win_ptr, 2, 1L<<0, key_press, &game));
	while (game.is_running)
	{
		printf("ici");
		mlx_loop(game.mlx_ptr);
	}
	return (game.win_ptr);
}