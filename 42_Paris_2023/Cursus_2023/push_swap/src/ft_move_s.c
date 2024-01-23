/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:36:56 by mechard           #+#    #+#             */
/*   Updated: 2024/01/19 19:20:02 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*move_sa(int *a)
{
	int	tmp;
	
	tmp = a[0];
	a[0] = a[1];
	a[1] = tmp;
	return (a);
}

int	*move_sb(int *b)
{
	int	tmp;
	
	tmp = b[0];
	b[0] = b[1];
	b[1] = tmp;
	return (b);
}

int	*move_ss(int *a, int *b)
{
	move_sa(a);
	move_sb(b);
	return (a, b);
}