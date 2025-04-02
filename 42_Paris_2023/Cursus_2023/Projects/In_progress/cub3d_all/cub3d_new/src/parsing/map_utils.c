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
		map_list = map_list->next, free(tmp);
	}
	cub->map[count] = NULL;
	cub->map_rows = count;
	if (!validate_map(cub->map))
		return (1);
	return (0);
}
