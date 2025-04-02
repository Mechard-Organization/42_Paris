/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 08:20:09 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 08:20:09 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int is_valid_extension(const char *filename)
{
	size_t len;
	if (!filename)
		return (0);
	len = ft_strlen(filename);
	if (len < 4)
		return (0);
	return (ft_strcmp((char *)(filename + len - 4), ".cub") == 0);
}

int is_header_line(const char *line)
{
	if (!line || !*line)
		return (0);
	if (ft_strncmp(line, "NO ", 3) == 0) return (1);
	if (ft_strncmp(line, "SO ", 3) == 0) return (1);
	if (ft_strncmp(line, "WE ", 3) == 0) return (1);
	if (ft_strncmp(line, "EA ", 3) == 0) return (1);
	if (ft_strncmp(line, "F ", 2) == 0) return (1);
	if (ft_strncmp(line, "C ", 2) == 0) return (1);
	return (0);
}

static int check_map_chars(char *line, int *start_count)
{
	int i = 0;
	while (line[i])
	{
		if (line[i] != '0' && line[i] != '1' &&
		    line[i] != 'N' && line[i] != 'S' &&
		    line[i] != 'E' && line[i] != 'W' &&
			line[i] != ' ')
			return (ft_putendl_fd("Error\nMap invalid", 2), 0);
		if (line[i] == 'N' || line[i] == 'S' ||
		    line[i] == 'E' || line[i] == 'W')
			(*start_count)++;
		i++;
	}
	return (1);
}

static int check_map_walls(char **map, int rows)
{
	int i, j, cols;
	cols = ft_strlen(map[0]);
	for (j = 0; j < cols; j++)
	{
		if (map[0][j] != '1' || map[rows - 1][j] != '1')
			return (0);
	}
	for (i = 0; i < rows; i++)
	{
		int len = ft_strlen(map[i]);
		if (len == 0 || map[i][0] != '1' ||
		    map[i][len - 1] != '1')
			return (0);
	}
	return (1);
}

int validate_map(char **map)
{
	int i, rows, start_count = 0;
	if (!map)
		return (0);
	for (rows = 0; map[rows]; rows++);
	for (i = 0; i < rows; i++)
	{
		if (!check_map_chars(map[i], &start_count))
			return (0);
	}
	if (start_count != 1)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid starting position", 2);
		return (0);
	}
	if (!check_map_walls(map, rows))
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Map is not surrounded by walls", 2);
		return (0);
	}
	return (1);
}

int convert_map_list(t_list *map_list, t_cub *cub)
{
	int count;
	t_list *tmp;
	count = ft_lstsize(map_list);
	cub->map = malloc(sizeof(char *) * (count + 1));
	if (!cub->map)
		return (1);
	count = 0;
	while (map_list)
	{
		cub->map[count++] = (char *)map_list->content;
		tmp = map_list;
		map_list = map_list->next;
		free(tmp);
	}
	cub->map[count] = NULL;
	cub->map_rows = count;
	if (count > 0)
		cub->map_cols = ft_strlen(cub->map[0]);
	if (!validate_map(cub->map))
		return (1);
	return (0);
}
