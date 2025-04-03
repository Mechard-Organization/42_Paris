/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:05:08 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:05:08 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
	{
		ft_putendl_fd("Error: mlx initialization failed", 2);
		return (1);
	}
	cub->win = mlx_new_window(cub->mlx, WIN_WIDTH, WIN_HEIGHT, "Cub3D");
	if (!cub->win)
	{
		ft_putendl_fd("Error: window creation failed", 2);
		return (1);
	}
	return (0);
}
