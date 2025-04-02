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

static int check_texture_file(const char *path)
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
		return (ft_putendl_fd("Error\nInvalid texture extension", 2), free(dup), 1);
	else if (access(dup, F_OK) != 0)
		return (ft_putendl_fd("Error\nTexture file not found", 2), free(dup), 1);
	return (free(dup), 0);
}

static int parse_color_line(char *line, int color[3])
{
	char	**nums;

	nums = ft_split(line + 2, ',');
	if (!nums || ft_dstrlen(nums) != 3)
		return (ft_putendl_fd("Error\nColor allocation error", 2), 1);
	color[0] = ft_atoi(nums[0]);
	color[1] = ft_atoi(nums[1]);
	color[2] = ft_atoi(nums[2]);
	free(nums[0]); free(nums[1]); free(nums[2]); free(nums);
	if ((color[0] > 255 || color[0] < 0) || (color[1] > 255 || color[1] < 0) ||
		(color[2] > 255 || color[2] < 0))
		return (ft_putendl_fd("Error\nColor allocation error", 2), 1);
	return (0);
}

static int elements_order(char *line, int expected)
{
	char	*exp[6];

	exp[0] = "NO";
	exp[1] = "SO";
	exp[2] = "WE";
	exp[3] = "EA";
	exp[4] = "F";
	exp[5] = "C";
	if (ft_strncmp(line, exp[expected],
		ft_strlen(exp[expected])) != 0)
	{
		ft_putendl_fd("Error\nHeader elements not in order or incomplete", 2);
		return (1);
	}
	return (0);
}

int parse_header_line(char *line, t_cub *cub, int expected)
{
	if (elements_order(line, expected))
		return (free_textures(cub), 1);
	if (expected == 0)
		cub->tex_no = ft_strdup(line + 3);
	else if (expected == 1)
		cub->tex_so = ft_strdup(line + 3);
	else if (expected == 2)
		cub->tex_we = ft_strdup(line + 3);
	else if (expected == 3)
		cub->tex_ea = ft_strdup(line + 3);
	else if (expected == 4)
		return (parse_color_line(line, cub->color_floor));
	else if (expected == 5)
		return (parse_color_line(line, cub->color_ceiling));
	if ((expected == 0 && check_texture_file(cub->tex_no)) ||
		(expected == 1 && check_texture_file(cub->tex_so)) ||
		(expected == 2 && check_texture_file(cub->tex_we)) ||
		(expected == 3 && check_texture_file(cub->tex_ea)))
		return (free_textures(cub), 1);
	return (0);
}
