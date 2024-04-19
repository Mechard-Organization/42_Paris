/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 10:37:22 by mechard           #+#    #+#             */
/*   Updated: 2024/03/21 12:32:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_dfree(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		free(str[i++]);
	free(str);
}

int	verif_name(char *str)
{
	while (*str)
		str++;
	str -= 4;
	if (ft_strncmp(str, ".ber", 4) == 0)
		return (0);
	return (1);
}

int	main(int ac, char **av)
{
	char	**map;
	int		i;

	map = NULL;
	if (ac != 2)
		return (ft_printf("Il n'y a pas le bon nombre d'arguments\n"), 0);
	map = verif_map(av[1], map);
	i = 0;
	while (map[i])
		ft_printf("%s", map[i++]);
	ft_printf("\n");
	open_windows();
	ft_dfree(map);
	return (0);
}
