/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/02 23:32:26 by mechard           #+#    #+#             */
/*   Updated: 2025/04/02 23:32:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int free_textures(t_cub *cub)
{
	if (cub->tex_no)
		free(cub->tex_no);
	if (cub->tex_so)
		free(cub->tex_so);
	if (cub->tex_we)
		free(cub->tex_we);
	if (cub->tex_ea)
		free(cub->tex_ea);
	return (0);
}