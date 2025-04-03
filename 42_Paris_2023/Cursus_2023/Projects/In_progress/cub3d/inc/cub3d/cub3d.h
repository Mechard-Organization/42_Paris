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
** Définitions de la taille de la fenêtre et des codes clavier
*/

# define WIN_WIDTH 800
# define WIN_HEIGHT 600

# define KEY_MAJ_L		65505
# define KEY_MAJ_R		65506
# define KEY_BACKWARD	65364
# define KEY_RIGHT		65363
# define KEY_FORWARD	65362
# define KEY_LEFT		65361
# define KEY_ESC		65307
# define KEY_Z			122
# define KEY_W			119
# define KEY_S			115
# define KEY_Q			113
# define KEY_D			100
# define KEY_A			97

/*
** Message d'erreur
*/

# define TEXT_EXT_ERROR "Error\nInvalid texture extension"

# define TEXT_NOT_FOUND "Error\nTexture file not found"

# define HEADER_INCOMPL "Error\nIncomplete or incorrect header"

# define FILE_FORMAT_IN "Error\nIncorrect file format"

# define FILE_EXTENS_IN "Error\nInvalid file extension"

# define FILE_CANT_OPEN "Error\nCannot open file"

# define MAP_INVALID "Error\nMap invalid"

# define MAP_NOT_FOUND "Error\nNo map found"

# define INVALID_STA_PO "Error\nInvalid starting position"

# define MAP_NOT_SURROU "Error\nMap is not surrounded by walls"

# define COLOR_ALLOC_ER "Error\nColor allocation error"

/*
** Structure pour les textures du projet Cub3D
*/
typedef struct s_img_cub
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}			t_img_cub;

/*
** Structure principale du projet Cub3D
*/
typedef struct s_cub
{
	void		*mlx;
	void		*win;
	char		*tex_no;
	char		*tex_so;
	char		*tex_we;
	char		*tex_ea;
	int			color_floor[3];
	int			color_ceiling[3];
	char		**map;
	int			map_rows;
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	int			pov_left;
	int			pov_right;
	int			move_left;
	int			move_right;
	int			move_forward;
	int			move_backward;
	int			sprint;
	int			exit;
	t_img_cub	img_tex_no;
	t_img_cub	img_tex_so;
	t_img_cub	img_tex_we;
	t_img_cub	img_tex_ea;
}	t_cub;

typedef struct s_render
{
	t_cub	*cub;
	int		x;
	char	*data;
	int		bpp;
	int		size_line;
}				t_render;

typedef struct s_ray_result
{
	int			side;
	double		perpwalldist;
	int			lineheight;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			texx;
	t_img_cub	*current_tex;
	/* Valeurs intermédiaires */
	double		camx;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		deltadistx;
	double		deltadisty;
	double		sidedistx;
	double		sidedisty;
	int			stepx;
	int			stepy;
	int			hit;
}				t_ray_result;

typedef struct s_exec
{
	void	*img;
	char	*data;
	int		bpp;
	int		sl;
}				t_exec;

typedef struct s_key
{
	double	ms;
	double	rs;
	double	strafex;
	double	strafey;
	double	olddirx;
	double	oldplanex;
}				t_key;

/* Parsing */
int		parse_file(char *filename, t_cub *cub);
int		parse_header_line(char *line, t_cub *cub);
int		is_valid_extension(const char *filename);
int		is_header_line(const char *line);
int		validate_map(char **map);
int		convert_map_list(t_list *map_list, t_cub *cub);
int		elements_order(char *line);

/* Exécution */
void	put_pixel(t_render *r, int y, int color);
void	set_initial_position_and_direction(t_cub *cub);
int		init_mlx(t_cub *cub);
int		get_texture_pixel(t_img_cub *tex, int x, int y);
void	render_column(t_render *r, t_ray_result *res);
void	render_column_ray(t_render *r, t_ray_result *res);
void	draw_column_pixels(t_render *r, t_ray_result *res);
void	compute_ray_params(t_render *r, t_ray_result *res);
void	run_dda(t_render *r, t_ray_result *res);
void	compute_distances(t_render *r, t_ray_result *res);
void	select_texture(t_render *r, t_ray_result *res);
void	compute_texture(t_render *r, t_ray_result *res);
void	draw_scene(t_cub *cub);
int		key_press_cub(int keycode, t_cub *cub);
int		key_release_cub(int keycode, t_cub *cub);
int		update_loop(t_cub *cub);
int		load_textures(t_cub *cub);
int		exit_hook(t_cub *cub);

/* Free */
int		free_textures(t_cub *cub);
int		free_all_cub(t_cub *cub);
int		free_lac(char *line, t_cub *cub);
void	free_cub(t_cub *cub);

#endif