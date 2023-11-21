/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: maechard <maechard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 03:47:36 by maechard          #+#    #+#             */
/*   Updated: 2017/11/27 03:47:38 by maechard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H
# include "libft/includes/libft.h"
# include "./minilibx/mlx.h"

typedef struct		s_all
{
	void			*mlx;
	void			*win;
}					t_all;

typedef struct 		s_zoom
{
	int		win_x;
	int		win_y;
	int		logr;
	int		lagr;
}					t_zoom;

void		fdf(char	*map);

#endif