/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:25:38 by mechard           #+#    #+#             */
/*   Updated: 2024/03/21 12:25:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *str)
{
	char	*tmp;
	int		fd;
	int		i;

	i = 0;
	fd = open(str, O_RDONLY);
	if (fd < 0 || fd > 1024 || read(fd, 0, 0) < 0)
	{
		ft_printf("Une erreur c'est produite durant l'ouverture du fichier\n");
		return (0);
	}
	tmp = ft_calloc(1, sizeof(char));
	if (!tmp)
		return (0);
	while (tmp)
	{
		free(tmp);
		tmp = get_next_line(fd);
		i++;
	}
	free(tmp);
	get_next_line(-1);
	close(fd);
	return (i);
}

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

int	check_cara(char **map, char *cara, t_map coor, t_so_long *nb)
{
	while (map[coor.y])
	{
		coor.x = 0;
		while (map[coor.y][coor.x] != '\n' && map[coor.y][coor.x])
		{
			coor.i = 0;
			while (map[coor.y][coor.x] != cara[coor.i] && cara[coor.i])
			{
				if (map[coor.y][coor.x] == 'P' && nb->nb_P == 0)
					nb->nb_P++;
				if (map[coor.y][coor.x] == 'E' && nb->nb_E == 0)
					nb->nb_E++;
				coor.i++;
			}
			if (cara[coor.i] == '\0')
			{
				ft_dfree(map);
				ft_printf("Le format de la map est incorrect\n", 0);
				exit(1);
			}
			coor.x++;
		}
		coor.y++;
	}
	return (0);
}

int	verif_cara(char **map)
{
	char		*cara;
	t_map		coor;
	t_so_long	nb;

	coor.y = 0;
	nb.nb_P = 0;
	nb.nb_E = 0;
	cara = "01CEP";
	check_cara(map, cara, coor, &nb);
	if (nb.nb_P != 1 || nb.nb_E != 1)
	{
		ft_dfree(map);
		ft_printf("Le nombre de spawn ou de sortie est incorrect\n", 0);
		exit(1);
	}
	return (0);
}

char	**verif_map(char *str, char **map)
{
	int	i;
	int	y;

	i = 0;
	y = 0;
	if (verif_name(str) == 1)
	{
		ft_printf("le nom de la map n'est pas valide\n");
		exit (1);
	}
	map = recup_map(str);
	if (verif_cara(map) == 1)
		exit (1);
	return (map);
}
