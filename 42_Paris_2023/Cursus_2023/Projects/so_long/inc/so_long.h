/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:38:25 by mechard           #+#    #+#             */
/*   Updated: 2024/03/21 12:34:56 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "ft_printf.h"
# include "libft.h"
# include "mlx.h"

typedef struct	s_so_long
{
	int	nb_P;
	int	nb_E;
}				t_so_long;

typedef struct	s_map
{
	int	x;
	int	y;
	int i;
}				t_map;

int		verif_name(char *str);
int		count_line(char *str);
int		open_windows();
int		check_cara(char **map, char *cara, t_map coor, t_so_long *nb);
int		verif_cara(char **map);

char	**recup_map(char	*str);
char	**verif_map(char *str, char **map);
int		check_cara(char **map, char *cara, t_map coor, t_so_long *nb);
int		verif_cara(char **map);

void	ft_dfree(char **str);

#endif