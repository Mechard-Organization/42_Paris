/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:58 by mechard           #+#    #+#             */
/*   Updated: 2023/11/21 15:28:11 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_rules(size_t ev, va_list arg)
{
	char 	*tmp_str;
	// int		*tmp_tint;
	// int		tmp_i;
	
	if (ev == 0)
	{
		tmp_str = (char *)va_arg(arg, char *);
		ft_putnbr_fd(ev, 0);
		return (1);
	}
	else if (ev == 4)
	{
		tmp_str = (char *)va_arg(arg, char *);
		ft_putstr_fd(tmp_str, 0);
		return (1);
	}
	return (0);
}

int	ft_parse(const char *str, va_list arg)
{
	size_t	i;
	size_t	ev;
	char	*flags;

	i = 1;
	ev = 0;
	flags = "cdipsuxX%";
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
