/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:38:25 by mechard           #+#    #+#             */
/*   Updated: 2024/05/10 17:19:13 by mechard          ###   ########.fr       */
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
    void    *mlx_ptr;
    void    *win_ptr;
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

char	**recup_map(char	*str);
char	**verif_map(char *str, char **map);
int		check_cara(char **map, char *cara, t_map coor, t_so_long *nb);
int		verif_cara(char **map);

void	ft_dfree(char **str);
void	*open_windows();

#endif