/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_exec.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 03:18:58 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 03:18:58 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	render_column(t_render *r, t_ray_result *res)
{
	render_column_ray(r, res);
	draw_column_pixels(r, res);
}

void	render_column_ray(t_render *r, t_ray_result *res)
{
	compute_ray_params(r, res);
	run_dda(r, res);
	compute_distances(r, res);
	select_texture(r, res);
	compute_texture(r, res);
}

void	draw_column_pixels(t_render *r, t_ray_result *res)
{
	int	y;
	int	color;
	int	d;
	int	texy;

	y = 0;
	while (y < res->drawstart)
	{
		color = (r->cub->color_ceiling[0] << 16)
			| (r->cub->color_ceiling[1] << 8)
			| r->cub->color_ceiling[2];
		put_pixel(r->data, r->x, y, color, r->size_line, r->bpp);
		y = y + 1;
	}
	while (y < res->drawend)
	{
		d = y * 256 - WIN_HEIGHT * 128 + res->lineheight * 128;
		texy = ((d * res->current_tex->height) / res->lineheight) / 256;
		color = get_texture_pixel(res->current_tex, res->texx, texy);
		put_pixel(r->data, r->x, y, color, r->size_line, r->bpp);
		y = y + 1;
	}
	while (y < WIN_HEIGHT)
	{
		color = (r->cub->color_floor[0] << 16)
			| (r->cub->color_floor[1] << 8)
			| r->cub->color_floor[2];
		put_pixel(r->data, r->x, y, color, r->size_line, r->bpp);
		y = y + 1;
	}
}
