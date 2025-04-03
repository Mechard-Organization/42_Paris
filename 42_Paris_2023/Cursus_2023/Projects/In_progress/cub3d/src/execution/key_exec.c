/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_exec.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/04 02:13:10 by mechard           #+#    #+#             */
/*   Updated: 2025/04/04 02:13:10 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	key_press_cub(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_FORWARD)
		cub->move_forward = 1;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub->move_backward = 1;
	else if (keycode == KEY_A || keycode == KEY_Q)
		cub->move_left = 1;
	else if (keycode == KEY_D)
		cub->move_right = 1;
	else if (keycode == KEY_RIGHT)
		cub->pov_right = 1;
	else if (keycode == KEY_LEFT)
		cub->pov_left = 1;
	else if (keycode == KEY_ESC)
		cub->exit = 1;
	return (0);
}

int	key_release_cub(int keycode, t_cub *cub)
{
	if (keycode == KEY_W || keycode == KEY_Z || keycode == KEY_FORWARD)
		cub->move_forward = 0;
	else if (keycode == KEY_S || keycode == KEY_BACKWARD)
		cub->move_backward = 0;
	else if (keycode == KEY_A || keycode == KEY_Q)
		cub->move_left = 0;
	else if (keycode == KEY_D)
		cub->move_right = 0;
	else if (keycode == KEY_RIGHT)
		cub->pov_right = 0;
	else if (keycode == KEY_LEFT)
		cub->pov_left = 0;
	else if (keycode == KEY_ESC)
		cub->exit = 0;
	return (0);
}

int	update_loop(t_cub *cub)
{
	double	ms;
	double	rs;
	double	strafex;
	double	strafey;
	double	olddirx;
	double	oldplanex;

	ms = 0.01;
	rs = 0.01;
	if (cub->exit)
		return (exit_hook(cub));
	else if (cub->move_forward)
	{
		if (cub->map[(int)(cub->posy)]
		[(int)(cub->posx + cub->dirx * ms)] != '1')
			cub->posx += cub->dirx * ms;
		if (cub->map[(int)(cub->posy + cub->diry * ms)]
		[(int)cub->posx] != '1')
			cub->posy += cub->diry * ms;
	}
	else if (cub->move_backward)
	{
		if (cub->map[(int)(cub->posy)]
		[(int)(cub->posx - cub->dirx * ms)] != '1')
			cub->posx -= cub->dirx * ms;
		if (cub->map[(int)(cub->posy - cub->diry * ms)]
		[(int)cub->posx] != '1')
			cub->posy -= cub->diry * ms;
	}
	else if (cub->move_left)
	{
		strafex = cub->diry;
		strafey = -cub->dirx;
		if (cub->map[(int)(cub->posy)][(int)(cub->posx + strafex * ms)] != '1')
			cub->posx += strafex * ms;
		if (cub->map[(int)(cub->posy + strafey * ms)][(int)cub->posx] != '1')
			cub->posy += strafey * ms;
	}
	else if (cub->move_right)
	{
		strafex = -cub->diry;
		strafey = cub->dirx;
		if (cub->map[(int)(cub->posy)][(int)(cub->posx + strafex * ms)] != '1')
			cub->posx += strafex * ms;
		if (cub->map[(int)(cub->posy + strafey * ms)][(int)cub->posx] != '1')
			cub->posy += strafey * ms;
	}
	else if (cub->pov_right)
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(rs) - cub->diry * sin(rs);
		cub->diry = olddirx * sin(rs) + cub->diry * cos(rs);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(rs) - cub->planey * sin(rs);
		cub->planey = oldplanex * sin(rs) + cub->planey * cos(rs);
	}
	else if (cub->pov_left)
	{
		olddirx = cub->dirx;
		cub->dirx = cub->dirx * cos(-rs) - cub->diry * sin(-rs);
		cub->diry = olddirx * sin(-rs) + cub->diry * cos(-rs);
		oldplanex = cub->planex;
		cub->planex = cub->planex * cos(-rs) - cub->planey * sin(-rs);
		cub->planey = oldplanex * sin(-rs) + cub->planey * cos(-rs);
	}
	draw_scene(cub);
	return (0);
}
