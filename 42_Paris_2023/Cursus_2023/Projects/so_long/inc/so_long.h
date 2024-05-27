/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:38:25 by mechard           #+#    #+#             */
/*   Updated: 2024/05/27 15:26:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct	s_so_long
{
	int	nb_P;
	int	nb_E;
}				t_so_long;

typedef struct 	s_game
{
	char	**map;
    void    *mlx_ptr;
    void    *win_ptr;
	int		keycode_prev;
    int     is_running;
} 				t_game;

typedef struct	s_map
{
	int	x;
	int	y;
	int i;
}				t_map;

int		verif_name(char *str);
int		count_line(char *str);
int		check_cara(char **map, char *cara, t_map coor, t_so_long *nb);
int		verif_cara(char **map);
int		check_cara(char **map, char *cara, t_map coor, t_so_long *nb);
int		verif_cara(char **map);
int		key_press(int keycode, t_game *game);
int		key_release(int keycode, t_game *game);

char	**recup_map(char	*str);
char	**verif_map(char *str, char **map);

void	ft_dfree(char **str);
void	*open_windows();
void	close_window(t_game *game);

#endif