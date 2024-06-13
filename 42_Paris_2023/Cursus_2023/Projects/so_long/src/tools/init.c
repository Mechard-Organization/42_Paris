/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 12:49:47 by mechard           #+#    #+#             */
/*   Updated: 2024/06/13 12:41:23 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**recup_map(char *str)
{
	int		i;
	int		fd;
	int		y;
	char	*tmp;
	char	**res;

	i = 0;
	y = count_line(str);
	if (y == 0)
		return (NULL);
	res = (char **)malloc(sizeof(char *) * y);
	if (!res)
		return (NULL);
	fd = open(str, O_RDONLY);
	tmp = get_next_line(fd);
	while (tmp)
	{
		res[i++] = tmp;
		tmp = get_next_line(fd);
	}
	res[i++] = tmp;
	get_next_line(-1);
	close(fd);
	return (res);
}

void	ft_init_null(t_game *game)
{
	game->i = 0;
	game->step = 0;
	game->exit = 0;
	game->col = NULL;
	game->exi = NULL;
	game->roc = NULL;
	game->sol = NULL;
	game->pla = NULL;
	game->canva = NULL;
	game->win_ptr = NULL;
	game->keycode_prev = 0;
	game->collectibles = 0;
	game->nb_collectibles = 0;
}
