/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:22:46 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 08:22:46 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*
 * Initialise la MLX, crée la fenêtre et définit la position du joueur.
 */
int init_mlx(t_cub *cub)
{
	cub->mlx = mlx_init();
	if (!cub->mlx)
		return (1);
	cub->win = mlx_new_window(cub->mlx, 800, 600, "Cub3D");
	if (!cub->win)
		return (1);
	cub->posX = 1.5;
	cub->posY = 1.5;
	cub->dirX = -1.0;
	cub->dirY = 0.0;
	cub->planeX = 0.0;
	cub->planeY = 0.66;
	return (0);
}

/*
 * Affiche la scène en dessinant un plafond et un sol.
 */
void draw_scene(t_cub *cub)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < 600)
	{
		x = 0;
		while (x < 800)
		{
			if (y < 300)
				color = (cub->color_ceiling[0] << 16) |
					(cub->color_ceiling[1] << 8) |
					(cub->color_ceiling[2]);
			else
				color = (cub->color_floor[0] << 16) |
					(cub->color_floor[1] << 8) |
					(cub->color_floor[2]);
			mlx_pixel_put(cub->mlx, cub->win, x, y, color);
			x++;
		}
		y++;
	}
}

/*
 * Gère les événements clavier (ici seule la touche ESC est traitée).
 */
int key_hook(int keycode, t_cub *cub)
{
	if (keycode == 65307)
		exit_hook(cub);
	return (0);
}

/*
 * Ferme proprement la fenêtre et libère les ressources.
 */
int exit_hook(t_cub *cub)
{
	free_cub(cub);
	mlx_destroy_window(cub->mlx, cub->win);
	exit(EXIT_SUCCESS);
	return (0);
}

/*
 * Libère toutes les ressources allouées dans cub.
 */
void free_cub(t_cub *cub)
{
	int	i;

	if (cub->tex_no)
		free(cub->tex_no);
	if (cub->tex_so)
		free(cub->tex_so);
	if (cub->tex_we)
		free(cub->tex_we);
	if (cub->tex_ea)
		free(cub->tex_ea);
	if (cub->map)
	{
		i = 0;
		while (cub->map[i])
		{
			free(cub->map[i]);
			i++;
		}
		free(cub->map);
	}
}
