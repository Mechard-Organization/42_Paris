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

/*
 * Parse une ligne de couleur et stocke les valeurs dans color.
 * Retourne 0 si tout est OK, 1 en cas d'erreur.
 */
int parse_color(char *line, int color[3])
{
	char	**nums;

	nums = ft_split(line, ',');
	if (!nums)
		return (1);
	color[0] = ft_atoi(nums[0]);
	color[1] = ft_atoi(nums[1]);
	color[2] = ft_atoi(nums[2]);
	free(nums[0]);
	free(nums[1]);
	free(nums[2]);
	free(nums);
	return (0);
}

/*
 * Traite une ligne d'en-tête et met à jour la structure cub.
 * Gère les textures (NO, SO, WE, EA) et les couleurs (F, C).
 */
int parse_header_line(char *line, t_cub *cub)
{
	if (ft_strncmp(line, "NO ", 3) == 0)
		cub->tex_no = ft_strdup(line + 3);
	else if (ft_strncmp(line, "SO ", 3) == 0)
		cub->tex_so = ft_strdup(line + 3);
	else if (ft_strncmp(line, "WE ", 3) == 0)
		cub->tex_we = ft_strdup(line + 3);
	else if (ft_strncmp(line, "EA ", 3) == 0)
		cub->tex_ea = ft_strdup(line + 3);
	else if (ft_strncmp(line, "F ", 2) == 0)
		return (parse_color(line + 2, cub->color_floor));
	else if (ft_strncmp(line, "C ", 2) == 0)
		return (parse_color(line + 2, cub->color_ceiling));
	return (0);
}
