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

int main(int argc, char **argv)
{
    t_cub cub;
    int ret;

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
    if (init_mlx(&cub) != 0)
    {
        ft_putendl_fd("Erreur d'init mlx", 2);
        free_cub(&cub);
        return (EXIT_FAILURE);
    }
    draw_scene(&cub);
    mlx_hook(cub.win, 2, 1L << 0, key_hook, &cub);
    mlx_hook(cub.win, 17, 0, exit_hook, &cub);
    mlx_loop(cub.mlx);
    free_cub(&cub);
    return (EXIT_SUCCESS);
}
