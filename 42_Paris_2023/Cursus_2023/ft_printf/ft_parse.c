/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:58 by mechard           #+#    #+#             */
/*   Updated: 2023/11/30 19:19:21 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_res	ft_rules(size_t ev, va_list arg)
{
	t_res	res;

	res.res = (char *)malloc(sizeof(char *) * 2);
	if (ev == 'c')
		res.res[0] = (char)va_arg(arg, int);
	else if (ev == 'd' || ev == 'i')
		res.res = ft_itoa((int)va_arg(arg, int));
	else if (ev == 'p')
		res.res = ft_convert_base(arg, "add");
	else if (ev == 'P')
		res.res = ft_convert_base(arg, "ADD");
	else if (ev == 's')
		res.res = (char *)va_arg(arg, char *);
	else if (ev == 'u')
		res.res = ft_convert_base(arg, "Dec");
	else if (ev == 'x')
		res.res = ft_convert_base(arg, "hex");
	else if (ev == 'X')
		res.res = ft_convert_base(arg, "HEX");
	else if (ev == '%')
		res.res[0] = '%';
	res.len_f = 1;
	return (res);
}

t_res	ft_brules(va_list arg, const char *str, size_t i)
{
	int		nb;
	t_res	res;

	res.res = NULL;
	res.len_f = 1;
	if (str[i] == '#')
	{
		if (str[i + res.len_f] == 'x')
			res.res = ft_strjoin("0x", ft_convert_base(arg, "hex"));
		else if (str[i + res.len_f] == 'X')
			res.res = ft_strjoin("0X", ft_convert_base(arg, "HEX"));
	}
	else if (str[i] == '+' || str[i] == ' ')
	{
		nb = (int)va_arg(arg, int);
		if ((str[i + res.len_f] == 'd' || str[i + res.len_f] == 'i')
			&& (str[i] == '+' || str[i] == ' ') && nb >= 0)
			res.res = "+";
		res.res = ft_strjoin(res.res, ft_itoa(nb));
	}
	if (res.res != NULL)
		res.len_f++;
	return (res);
}

t_res	ft_parse(const char *str, int len, va_list arg)
{
	size_t	ev;
	t_res	res;
	char	*flags;
	char	*bonus;

	ev = 0;
	bonus = "# +";
	flags = "cdipPsuxX%";
	while (str[len + 1])
	{
		ev = 0;
		len++;
		while (flags[ev])
		{
			if (str[len] == flags[ev])
				return (ft_rules(flags[ev], arg));
			else if (str[len] == bonus[ev])
				return (ft_brules(arg, str, len));
			ev++;
		}
	}
	res.res = NULL;
	return (res);
}
