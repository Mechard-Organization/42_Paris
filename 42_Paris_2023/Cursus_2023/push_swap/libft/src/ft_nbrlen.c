/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 15:02:52 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:35:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

size_t	ft_nbrlen(long n, int base)
{
	size_t	len;
	int		isneg;

	len = 0;
	isneg = 0;
	if (n < 0)
	{
		len++;
		isneg++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= base;
	}
	return (len);
}
