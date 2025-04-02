/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:04:20 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 08:04:20 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "libft.h"

/*
** Structure principale du projet Cub3D
*/
typedef struct s_cub
{
	void	*mlx;
	void	*win;
	char	*tex_no;
	char	*tex_so;
	char	*tex_we;
	char	*tex_ea;
	int		color_floor[3];
	int		color_ceiling[3];
	char	**map;
	int		map_rows;
	int		map_cols;
	double	posX;
	double	posY;
	double	dirX;
	double	dirY;
	double	planeX;
	double	planeY;
}	t_cub;

/* Parsing */
int	parse_file(char *filename, t_cub *cub);
int	parse_header_line(char *line, t_cub *cub, int expected);
int	is_valid_extension(const char *filename);
int	is_header_line(const char *line);
int	convert_map_list(t_list *map_list, t_cub *cub);

/* Exécution */
int	init_mlx(t_cub *cub);
void	draw_scene(t_cub *cub);
int	key_hook(int keycode, t_cub *cub);
int	exit_hook(t_cub *cub);
void	free_cub(t_cub *cub);

#endif