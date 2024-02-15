/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_quicksort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:45:14 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:08:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

void	ft_quicksort(double *tab, size_t len, int rev)
{
	size_t	i;
	size_t	wall;
	double	pivot;
	double	tmp;

	if (len < 2)
		return ;
	pivot = tab[len - 1];
	wall = 0;
	i = -1;
	while (++i < len)
	{
		if (tab[i] <= pivot)
		{
			if (wall != 1)
			{
				tmp = tab[i];
				tab[i] = tab[wall];
				tab[wall] = tmp;
			}
			wall++;
		}
	}
	ft_quicksort(tab, wall - 1, rev);
	ft_quicksort(tab + wall - 1, len - wall + 1, rev);
}
