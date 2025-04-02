/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 09:00:16 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 09:00:16 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_texture_file(const char *path)
{
	size_t	len;
	char	*dup;

	if (!path)
		return (1);
	dup = ft_strdup(path);
	if (!dup)
		return (1);
	len = ft_strlen(dup);
	while (len > 0 && (dup[len - 1] == '\n' || dup[len - 1] == '\r'))
	{
		dup[len - 1] = '\0';
		len = ft_strlen(dup);
	}
	if (len < 4 || ft_strcmp((char *)(dup + len - 4), ".xpm") != 0)
		return (ft_putendl_fd(TEXT_EXT_ERROR, 2), free(dup), 1);
	else if (access(dup, F_OK) != 0)
		return (ft_putendl_fd(TEXT_NOT_FOUND, 2), free(dup), 1);
	return (free(dup), 0);
}

static int	parse_color_line(char *line, int color[3])
{
	char	**nums;

	nums = ft_split(line + 2, ',');
	if (!nums || ft_dstrlen(nums) != 3)
		return (ft_putendl_fd("Error\nColor allocation error", 2), 1);
	color[0] = ft_atoi(nums[0]);
	color[1] = ft_atoi(nums[1]);
	color[2] = ft_atoi(nums[2]);
	(free(nums[0]), free(nums[1]), free(nums[2]), free(nums));
	if ((color[0] > 255 || color[0] < 0) || (color[1] > 255 || color[1] < 0)
		|| (color[2] > 255 || color[2] < 0))
		return (ft_putendl_fd("Error\nColor allocation error", 2), 1);
	return (0);
}

int	elements_order(char *line)
{
	char	*exp[6];
	int		i;

	exp[0] = "NO";
	exp[1] = "SO";
	exp[2] = "WE";
	exp[3] = "EA";
	exp[4] = "F";
	exp[5] = "C";
	i = 0;
	while (i < 6)
	{
		if (!ft_strncmp(line, exp[i], ft_strlen(exp[i])))
			return (i);
		i++;
	}
	if (line[1] == '\n')
		return (i);
	else
		return (i + 1);
}

int	parse_header_line(char *line, t_cub *cub)
{
	int	header;

	header = elements_order(line);
	if (header == 0 && !cub->tex_no)
		cub->tex_no = ft_strdup(line + 3);
	else if (header == 1 && !cub->tex_so)
		cub->tex_so = ft_strdup(line + 3);
	else if (header == 2 && !cub->tex_we)
		cub->tex_we = ft_strdup(line + 3);
	else if (header == 3 && !cub->tex_ea)
		cub->tex_ea = ft_strdup(line + 3);
	else if (header == 4 && cub->color_floor[0] == -1)
		return (parse_color_line(line, cub->color_floor));
	else if (header == 5 && cub->color_ceiling[0] == -1)
		return (parse_color_line(line, cub->color_ceiling));
	else
		return (ft_putendl_fd("Error\nIncomplete or incorrect header", 2), free_textures(cub), 1);
	if ((header == 0 && check_texture_file(cub->tex_no))
		|| (header == 1 && check_texture_file(cub->tex_so))
		|| (header == 2 && check_texture_file(cub->tex_we))
		|| (header == 3 && check_texture_file(cub->tex_ea))
		|| header == 6)
		return (free_textures(cub), 1);
	return (0);
}
