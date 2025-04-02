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

/*
 * Vérifie que le chemin se termine par ".xpm" et que le fichier existe.
 */
static int check_texture_file(const char *path)
{
	size_t	len;
	char	*dup;
	int		ret;

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
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Invalid texture extension", 2);
		ret = 1;
	}
	else if (access(dup, F_OK) != 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Texture file not found", 2);
		ret = 1;
	}
	else
		ret = 0;
	free(dup);
	return (ret);
}

/*
 * Parse une ligne de couleur (F ou C) et stocke le résultat.
 */
static int parse_color_line(char *line, int color[3])
{
	char	**nums;

	nums = ft_split(line + 2, ',');
	if (!nums)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Memory allocation error", 2);
		return (1);
	}
	color[0] = ft_atoi(nums[0]);
	color[1] = ft_atoi(nums[1]);
	color[2] = ft_atoi(nums[2]);
	free(nums[0]); free(nums[1]); free(nums[2]); free(nums);
	return (0);
}

/*
 * Parse une ligne d'en-tête et met à jour cub.
 * expected est l'indice attendu (0=NO,1=SO,2=WE,3=EA,4=F,5=C).
 */
int parse_header_line(char *line, t_cub *cub, int expected)
{
	const char	*exp[6] = {"NO", "SO", "WE", "EA", "F", "C"};

	if (ft_strncmp(line, exp[expected],
			ft_strlen(exp[expected])) != 0)
	{
		ft_putendl_fd("Error", 2);
		ft_putendl_fd("Header elements not in order", 2);
		return (1);
	}
	if (expected < 4)
	{
		if (expected == 0)
			cub->tex_no = ft_strdup(line + 3);
		else if (expected == 1)
			cub->tex_so = ft_strdup(line + 3);
		else if (expected == 2)
			cub->tex_we = ft_strdup(line + 3);
		else if (expected == 3)
			cub->tex_ea = ft_strdup(line + 3);
		if (!((expected == 0 && cub->tex_no) ||
			(expected == 1 && cub->tex_so) ||
			(expected == 2 && cub->tex_we) ||
			(expected == 3 && cub->tex_ea)))
			return (1);
		if (expected == 0 && check_texture_file(cub->tex_no))
			return (1);
		if (expected == 1 && check_texture_file(cub->tex_so))
			return (1);
		if (expected == 2 && check_texture_file(cub->tex_we))
			return (1);
		if (expected == 3 && check_texture_file(cub->tex_ea))
			return (1);
	}
	else
	{
		if (expected == 4)
			return (parse_color_line(line, cub->color_floor));
		else if (expected == 5)
			return (parse_color_line(line, cub->color_ceiling));
	}
	return (0);
}
