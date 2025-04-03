/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:13:58 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:13:58 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pixel(char *data, int x, int y, int color, int size_line, int bpp)
{
	int	idx;

	idx = (y * size_line) + (x * (bpp / 8));
	*(int *)(data + idx) = color;
}

int	exit_hook(t_cub *cub)
{
	mlx_destroy_window(cub->mlx, cub->win);
	free_all_cub(cub);
	exit(0);
	return (0);
}
