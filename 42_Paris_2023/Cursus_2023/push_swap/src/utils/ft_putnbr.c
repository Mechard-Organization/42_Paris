/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:11:48 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 13:18:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

void	ft_putnbr_fd(int n)
{
	unsigned int	nb;

	if (n < 0)
	{
		nb = -n;
		ft_putchar_fd('-');
	}
	else
		nb = n;
	if (nb >= 10)
	{
		ft_putnbr_fd((nb / 10));
		ft_putchar_fd(((nb % 10) + '0'));
	}
	else
	{
		if (n > 0)
			ft_putchar_fd(('0' + n));
		else
			ft_putchar_fd(('0' - n));
	}
}
