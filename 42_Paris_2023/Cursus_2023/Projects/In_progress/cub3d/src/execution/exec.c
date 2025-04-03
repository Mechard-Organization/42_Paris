/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/03 18:31:15 by mechard           #+#    #+#             */
/*   Updated: 2025/04/03 18:31:15 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	run_dda(t_render *r, t_ray_result *res)
{
	while (res->hit == 0)
	{
		if (res->sidedistx < res->sidedisty)
		{
			res->sidedistx = res->sidedistx + res->deltadistx;
			res->mapx = res->mapx + res->stepx;
			res->side = 0;
		}
		else
		{
			res->sidedisty = res->sidedisty + res->deltadisty;
			res->mapy = res->mapy + res->stepy;
			res->side = 1;
		}
		if (r->cub->map[res->mapy][res->mapx] == '1')
			res->hit = 1;
	}
}

void	draw_scene(t_cub *cub)
{
	void	*img;
	char	*data;
	int		bpp;
	int		size_line;
	int		x;

	x = 0;
	img = mlx_new_image(cub->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (img == 0)
		return ;
	data = mlx_get_data_addr(img, &bpp, &size_line, &(int){0});
	while (x < WIN_WIDTH)
	{
		t_render		r;
		t_ray_result	res;
		r.cub = cub;
		r.x = x;
		r.data = data;
		r.bpp = bpp;
		r.size_line = size_line;
		render_column(&r, &res);
		x = x + 1;
	}
	mlx_put_image_to_window(cub->mlx, cub->win, img, 0, 0);
	mlx_destroy_image(cub->mlx, img);
}
