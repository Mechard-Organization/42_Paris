/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/21 12:29:38 by mechard           #+#    #+#             */
/*   Updated: 2024/03/21 12:44:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_window()
{
	exit(0);
	return (0);
}

int		create_map(char **str)
{
	
}

int		open_windows()
{
	void	*mlx_ptr;
	void	*win_ptr;

	mlx_ptr = mlx_init();
	win_ptr = mlx_new_window(mlx_ptr, 800, 600, "so_long");
	mlx_hook(win_ptr, 17, 0, close_window, NULL);

	mlx_loop(mlx_ptr);
	return (0);
}