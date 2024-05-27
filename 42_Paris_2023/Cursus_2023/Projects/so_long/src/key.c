/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 13:04:44 by mechard           #+#    #+#             */
/*   Updated: 2024/05/27 14:16:41 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		key_press(int keycode, t_game *game)
{
	// printf("keycode = %d\n", keycode);
	if  (keycode == 65507)
		game->keycode_prev = 1;
    if (keycode == 65307)
		close_window(game);
	if ((keycode == 100 || keycode == 99) && game->keycode_prev == 1)
		close_window(game);
    return (0);
}

int		key_release(int keycode, t_game *game)
{
	// printf("keycode = %d\n", keycode);
	if  (keycode == 65507)
		game->keycode_prev = 0;
	return (0);
}