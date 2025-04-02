/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:09:21 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 09:09:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int read_header(int fd, t_cub *cub)
{
	int header;
	char *line;

	header = 0;
	line = get_next_line(fd);
	while (header < 6 && line)
	{
		if (line[1] == '\n')
			free(line);
		else
		{
			if (parse_header_line(line, cub, header))
				return (free(line), 1);
			free(line);
			header++;
		}
		line = get_next_line(fd);
	}
	if (line)
		free(line);
	if (header < 6)
		return (ft_putendl_fd("Error\nIncomplete header", 2), 1);
	return (0);
}

static int read_map(int fd, t_list **list)
{
	char *line;
	t_list *tmp;

	line = get_next_line(fd);
	if (line[1] == '\n')
	{
		free(line);
		line = get_next_line(fd);
	}
	while (line)
	{
		if (ft_strlen(line) == 0)
			return (free(line), 1);
		tmp = ft_lstnew(ft_strdup(line));
		if (!tmp)
			return (free(line), 1);
		free(line);
		ft_lstadd_back(list, tmp);
		line = get_next_line(fd);
	}
	return (0);
}

int parse_file(char *filename, t_cub *cub)
{
	int fd;
	t_list *list;

	list = NULL;
	if (!is_valid_extension(filename))
		return (ft_putendl_fd("Error\nInvalid file extension", 2), 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error\nCannot open file", 2), 1);
	if (read_header(fd, cub))
		return (get_next_line(-1), close(fd), 1);
	if (read_map(fd, &list))
		return (get_next_line(-1), close(fd), 1);
	close(fd);
	if (!list)
		return (get_next_line(-1), ft_putendl_fd("Error\nNo map found", 2), 1);
	return (get_next_line(-1), convert_map_list(list, cub));
}
