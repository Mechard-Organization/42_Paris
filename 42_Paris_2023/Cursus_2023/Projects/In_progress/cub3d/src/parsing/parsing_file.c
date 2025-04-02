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

/*
 * Lit 6 lignes d'en-tête pouvant être séparé par autant de ligne vide que voulu.
 */
static int read_header(int fd, t_cub *cub)
{
	int header = 0;
	char *line;
	while (header < 6 && (line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) == 2)
		{
			free(line);
			continue;
		}
		if (parse_header_line(line, cub, header))
		{
			free(line);
			return (1);
		}
		free(line);
		header++;
	}
	if (header < 6)
		return (ft_putendl_fd("Error", 2),
			ft_putendl_fd("Incomplete header", 2), 1);
	return (0);
}

/*
 * Lit les lignes non vides de la map et les ajoute à une liste.
 */
static int read_map(int fd, t_list **list)
{
	char *line;
	t_list *tmp;
	while ((line = get_next_line(fd)) != NULL)
	{
		if (ft_strlen(line) == 0)
		{
			free(line);
			continue;
		}
		tmp = ft_lstnew(ft_strdup(line));
		if (!tmp)
		{
			free(line);
			return (1);
		}
		free(line);
		ft_lstadd_back(list, tmp);
	}
	return (0);
}

/*
 * parse_file: lit le fichier .cub et assemble header et map.
 */
int parse_file(char *filename, t_cub *cub)
{
	int fd;
	t_list *list;
	int ret;

	ret = 0;
	list = NULL;
	if (!is_valid_extension(filename))
		return (ft_putendl_fd("Error", 2),
			ft_putendl_fd("Invalid file extension", 2), 1);
	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (ft_putendl_fd("Error", 2),
			ft_putendl_fd("Cannot open file", 2), 1);
	if (read_header(fd, cub))
		return (close(fd), 1);
	if (read_map(fd, &list))
		return (close(fd), 1);
	close(fd);
	if (!list)
		return (ft_putendl_fd("Error", 2),
			ft_putendl_fd("No map found", 2), 1);
	ft_printf("ret before = %d\n", ret);
	ret = convert_map_list(list, cub);
	ft_printf("ret after = %d\n", ret);
	return (ret);
}
