/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:38:25 by mechard           #+#    #+#             */
/*   Updated: 2024/06/18 12:14:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"
# include "mlx_int.h"
# include <X11/X.h>
# include <X11/keysym.h>

# ifndef INVALID_NAME
#  define INVALID_NAME "Error\nLa nom de la map n'est pas valide\n"
# endif

# ifndef INVALID_MAP
#  define INVALID_MAP "Error\nLa map n'est pas valide\n"
# endif

# ifndef INVALID_NB
#  define INVALID_NB "Error\nLe nombre de spawn ou de sortie n'est pas valide ! \
(Maximum 1 de chaque)\n"
# endif

# ifndef INVALID_COL
#  define INVALID_COL "Error\nLe nombre de collectibles n'est pas valide ! (Au \
moins 1)\n"
# endif

# ifndef ERROR_COL
#  define ERROR_COL "Error\nUne erreur est survenue lors de la recuperation des \
collectibles\n"
# endif

# ifndef VALID_CARA
#  define VALID_CARA "01CEP"
# endif

# ifndef SUCCESS
#  define SUCCESS "\rBravo ! Vous avez gagne la partie !\nLe nombre de pas pendant \
cette partie est de %d\n "
# endif

typedef struct s_game
{
	int		i;
	char	**map;
	int		width;
	int		len;
	int		nb_collectibles;

	void	*col;
	void	*exi;
	void	*roc;
	void	*sol;
	void	*pla;
	t_img	*canva;

	int		step;
	int		exit;
	int		player_x;
	int		player_y;
	int		collectibles;

	void	*mlx_ptr;
	void	*win_ptr;
	int		keycode_prev;
}			t_game;

typedef struct s_map
{
	int		player_x;
	int		player_y;

	int		x;
	int		y;
	int		i;
	int		width;
	int		len;

	int		nb_p;
	int		nb_c;
	int		nb_e;
}			t_map;

int			verif_name(char *str);
int			count_line(char *str);
int			check_cara(char **map, char *cara, t_map *coor);
int			verif_cara(char **map, t_map *coor);
int			key_press(int keycode, t_game *game);
int			key_release(int keycode, t_game *game);
int			ft_init_sprites(t_game *game);
int			ft_set_img(t_game *game);

char		**recup_map(char *str);
char		**verif_map(char *str, char **map, t_game *game);

void		ft_dfree(char **str);
void		free_game(t_game *game);
void		ft_init_null(t_game *game);
void		*open_windows(t_game *game);
void		close_window(t_game *game);
void		ft_coor(int x, int y, t_map *coor);
void		draw_sprite(t_game *game, t_img *img, int x, int y);
void		move_player(int keycode, t_game *game);
void		ft_finish(t_game *game);

#endif