/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:59:14 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 07:59:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->tex_no = NULL;
	cub->tex_so = NULL;
	cub->tex_we = NULL;
	cub->tex_ea = NULL;
	cub->color_floor[0] = -1;
	cub->color_ceiling[0] = -1;
	cub->pov_left = 0;
	cub->pov_right = 0;
	cub->move_left = 0;
	cub->move_right = 0;
	cub->move_forward = 0;
	cub->move_backward = 0;
	cub->exit = 0;
	cub->map = NULL;
}

void	set_initial_position_and_direction(t_cub *cub)
{
	int		row;
	int		col;
	char	c;

	row = 0;
	while (cub->map[row])
	{
		col = 0;
		while (cub->map[row][col])
		{
			c = cub->map[row][col];
			if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
			{
				cub->posx = col + 0.5;
				cub->posy = row + 0.5;
				if (c == 'N')
				{
					cub->dirx = 0.0;
					cub->diry = -1.0;
					cub->planex = 0.66;
					cub->planey = 0.0;
				}
				else if (c == 'S')
				{
					cub->dirx = 0.0;
					cub->diry = 1.0;
					cub->planex = -0.66;
					cub->planey = 0.0;
				}
				else if (c == 'W')
				{
					cub->dirx = 1.0;
					cub->diry = 0.0;
					cub->planex = 0.0;
					cub->planey = 0.66;
				}
				else if (c == 'E')
				{
					cub->dirx = -1.0;
					cub->diry = 0.0;
					cub->planex = 0.0;
					cub->planey = -0.66;
				}
				cub->map[row][col] = '0';
				return ;
			}
			col++;
		}
		row++;
	}
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	int		ret;

	init_cub(&cub);
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <fichier.cub>", 2);
		return (EXIT_FAILURE);
	}
	ret = parse_file(argv[1], &cub);
	if (ret != 0)
	{
		if (ret != -1)
			ft_putendl_fd("Erreur de parsing", 2);
		return (EXIT_FAILURE);
	}
	set_initial_position_and_direction(&cub);
	if (init_mlx(&cub) || load_textures(&cub))
		return (free_all_cub(&cub), EXIT_FAILURE);
	(draw_scene(&cub), mlx_hook(cub.win, 2, 1L << 0, key_press_cub, &cub));
	mlx_hook(cub.win, 3, 1L << 1, key_release_cub, &cub);
	mlx_hook(cub.win, 17, 0, exit_hook, &cub);
	(mlx_loop_hook(cub.mlx, update_loop, &cub), mlx_loop(cub.mlx));
	return (free_all_cub(&cub), EXIT_SUCCESS);
}
