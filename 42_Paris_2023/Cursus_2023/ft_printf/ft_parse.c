/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:58 by mechard           #+#    #+#             */
/*   Updated: 2023/11/27 14:35:54 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rules(size_t ev, va_list arg)
{
	if (ev == 'c')
		return (ft_putchar_fd((int)va_arg(arg, int), 0), 0);
	else if (ev == 'd' || ev == 'i')
		return (ft_putnbr_fd((int)va_arg(arg, int), 0), 0);
	else if (ev == 'p')
		return (ft_putstr_fd(ft_convert_base(arg, "add"), 0), 0);
	else if (ev == 'P')
		return (ft_putstr_fd(ft_convert_base(arg, "ADD"), 0), 0);
	else if (ev == 's')
		return (ft_putstr_fd((char *)va_arg(arg, char *), 0), 0);
	else if (ev == 'u')
		return (ft_putstr_fd(ft_convert_base(arg, "Dec"), 0), 0);
	else if (ev == 'x')
		return (ft_putstr_fd(ft_convert_base(arg, "hex"), 0), 0);
	else if (ev == 'X')
		return (ft_putstr_fd(ft_convert_base(arg, "HEX"), 0), 0);
	else if (ev == '%')
		return (ft_putchar_fd('%', 0), 0);
	return (-1);
}

int	ft_brules(va_list arg, const char *str, size_t i)
{
	int	nb;

	if (str[i] == '#')
	{
		i++;
		if (str[i] == 'x')
			return (ft_putstr_fd("0x", 0), ft_putstr_fd(ft_convert_base(arg,
						"hex"), 0), 1);
		else if (str[i] == 'X')
			return (ft_putstr_fd("0X", 0), ft_putstr_fd(ft_convert_base(arg,
						"HEX"), 0), 1);
	}
	else if (str[i] == '+' || str[i] == ' ')
	{
		nb = (int)va_arg(arg, int);
		if ((str[i + 1] == 'd' || str[i + 1] == 'i') && (str[i] == '+'
				|| str[i] == ' '))
		{
			if (nb >= 0)
				return (ft_putchar_fd(str[i], 0), ft_putnbr_fd(nb, 0), 1);
			return (ft_putnbr_fd(nb, 0), 1);
		}
	}
	return (0);
}

int	ft_parse(const char *str, va_list arg)
{
	size_t	i;
	size_t	ev;
	char	*flags;
	char	*bonus;

	i = 1;
	ev = 0;
	flags = "cdipPsuxX%";
	bonus = "# +";
	while (str[i])
	{
		ev = 0;
		while (flags[ev])
		{
			if (str[i] == flags[ev])
				return (ft_rules(flags[ev], arg));
			if (str[i] == bonus[ev])
				return (ft_brules(arg, str, i), i++);
			ev++;
		}
		i++;
	}
	return (i);
}
