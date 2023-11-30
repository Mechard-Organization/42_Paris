/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:17 by mechard           #+#    #+#             */
/*   Updated: 2023/11/30 19:19:23 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_display(const char *str, va_list arg)
{
	int		len;
	int		tmp;
	t_res	res;
	char	*dis;

	len = 0;
	dis = NULL;
	res.len = 0;
	while (str[len])
	{
		if (str[len] != '%')
			ft_putchar_fd(str[len], 1);
		else
		{
			tmp = res.len;
			res = ft_parse(str, len, arg);
			if (!res.res)
				return (ft_putstr_fd("\nErreur d'arguments !\n", 1), 22);
			len += res.len_f;
			res.len += tmp + (int)ft_strlen(res.res) - res.len_f;
			ft_putstr_fd(res.res, 1);
		}
		res.len++;
		len++;
	}
	res.len++;
	// printf("\nres.len_f = %d\n", res.len_f);
	// printf("res.len = %d\n\n", res.len);
	// printf("len = %d\n\n", len);
	// ft_putstr_fd(dis, 1);
	return (res.len);
}

int	ft_printf(const char *form, ...)
{
	va_list	arg;
	int		i;

	i = 0;
	va_start(arg, form);
	i = ft_display(form, arg);
	va_end(arg);
	return (i);
}
