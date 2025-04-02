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
	else if (ret == 0)
		ft_printf("parsing réussi !\n");
    return (EXIT_SUCCESS);
}
