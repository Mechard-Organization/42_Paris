/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 12:49:58 by mechard           #+#    #+#             */
/*   Updated: 2023/12/01 16:14:25 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

t_res	ft_rules(size_t ev, t_res res, va_list arg)
{
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
	if (!res.res)
		res.res = "(null)";
	return (res);
}

t_res	ft_brules(va_list arg, const char *str, t_res res, size_t i)
{
	int		nb;
	
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
t_res	ft_space(const char *str, t_res res)
{
	int	i;

	i = ft_atoi(str);
	res.space_id = i;
	while(ft_isdigit(str[i]) == 1)
		i++;
	while (i > 0)
	{
		res.res = ft_strjoin(res.res, " ");
		i--;
	}
	return (res);
}

t_res	ft_parse(const char *str, int len, va_list arg)
{
	size_t	ev;
	t_res	res;
	char	*flags;
	char	*bonus;

	ev = 0;
	res.len_f = 1;
	bonus = "# +";
	flags = "cdipPsuxX%";
	res.res = (char *)malloc(sizeof(char *) * 2);
	while (str[len + 1])
	{
		ev = 0;
		len++;
		while (flags[ev])
		{
			if (str[len] == flags[ev])
				return (ft_rules(flags[ev], res, arg));
			else if (str[len] == bonus[ev])
				return (ft_brules(arg, str, res, len));
			ev++;
		}
	}
	return (res);
}
