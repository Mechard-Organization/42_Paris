/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 07:59:14 by mechard           #+#    #+#             */
/*   Updated: 2025/03/29 07:59:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init_cub(t_cub *cub)
{
	cub->mlx = NULL;
	cub->win = NULL;
	cub->tex_no = NULL;
	cub->tex_so = NULL;
	cub->tex_we = NULL;
	cub->tex_ea = NULL;
	cub->color_floor[0] = -1;
	cub->color_ceiling[0] = -1;
	cub->map = NULL;
}

int	main(int argc, char **argv)
{
	t_cub	cub;
	int		ret;

	init_cub(&cub);
	if (argc != 2)
	{
		ft_putendl_fd("Usage: ./cub3D <fichier.cub>", 2);
		return (EXIT_FAILURE);
	}
	ret = parse_file(argv[1], &cub);
	if (ret != 0)
	{
		if (ret != -1)
			ft_putendl_fd("Erreur de parsing", 2);
		return (EXIT_FAILURE);
	}
	else if (ret == 0)
		ft_printf("parsing réussi !\n");
	return (free_all_cub(&cub), EXIT_SUCCESS);
}

/*Faire la partie math en vectoriel !*/