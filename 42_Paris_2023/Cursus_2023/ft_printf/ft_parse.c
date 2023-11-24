/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:58 by mechard           #+#    #+#             */
/*   Updated: 2023/11/24 14:55:25 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rules(size_t ev, va_list arg)
{
	// printf("-----Test_rules-----\n");
	if (ev == 0)
		return (ft_putchar_fd((int)va_arg(arg, int), 0), 1);
	else if (ev == 1 || ev == 2)
		return (ft_putnbr_fd((int)va_arg(arg, int), 0), 1);
	else if (ev == 3)
		return (ft_putstr_fd(ft_convert_base(arg, "add"), 0), 1);
	else if (ev == 4)
		return (ft_putstr_fd(ft_convert_base(arg, "ADD"), 0), 1);
	else if (ev == 5)
		return (ft_putstr_fd((char *)va_arg(arg, char *), 0), 1);
	else if (ev == 6)
		return (ft_putstr_fd(ft_convert_base(arg,"Dec"), 0), 1);
	else if (ev == 7)
		return (ft_putstr_fd(ft_convert_base(arg,"hex"), 0), 1);
	else if (ev == 8)
		return (ft_putstr_fd(ft_convert_base(arg,"HEX"), 0), 1);
	else if (ev == 9)
		return(ft_putchar_fd('%', 0), 1);
	return (-1);
}

int	ft_parse(const char *str, va_list arg)
{
	size_t	i;
	size_t	ev;
	char	*flags;

	i = 1;
	ev = 0;
	flags = "cdipPsuxX%";
	// printf("-----Test_parse-----\n");
	while (str[i])
	{
		ev = 0;
		while (flags[ev])
		{
			if (str[i] == flags[ev])
				return (ft_rules(ev, arg));
			ev++;
		}
		i++;
	}
	return (i);
}
