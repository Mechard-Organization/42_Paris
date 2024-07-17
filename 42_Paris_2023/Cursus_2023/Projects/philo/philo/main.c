/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:09 by mechard           #+#    #+#             */
/*   Updated: 2024/07/17 15:15:05 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	(void)av;
	if (ac != 4)
		return (ft_putstr_fd("le nombre d'arguments est invalide !", 1), 1);
	ft_putstr_fd("BG", 1);
	return (0);
}
