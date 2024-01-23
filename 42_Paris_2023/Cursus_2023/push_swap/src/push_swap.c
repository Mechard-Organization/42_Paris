/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:49:27 by mechard           #+#    #+#             */
/*   Updated: 2024/01/19 19:12:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int		*ft_sort(int *a)
{
	int	*b;

	return (b);	
}

int		main(int ac, char **av)
{
	int		*tab;
	int		i;
	int		j;
	int		k;

	i = 1;
	k = 0;
	if (ac == 1)
		return (1);
	tab = (int*)malloc(sizeof(int) * (ac - 1));
	if (!tab)
		return (1);
	else
	{
		while (av[i])
		{
			j = 0;
			while (ft_isdigit(av[i][j]) == 1 && ft_isalpha(av[i][j]) == 0)
				j++;
			if (ft_isalpha(av[i][j]) == 1)
				return (ft_putstr_fd("Error\n", 1), 1);
			if (ft_isdigit(av[i][j]) == 0 && ft_isdigit(av[i][j - 1]) == 1)
			{
				tab[k] = ft_atoi(av[i]);
				k++;
			}
			i++;
		}
	}
	return (0);
}