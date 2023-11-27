/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:17 by mechard           #+#    #+#             */
/*   Updated: 2023/11/27 14:38:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display(const char *str, va_list arg)
{
	size_t	f;

	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str, 0);
		else
		{
			f = 0;
			if (*str - 2 == '#' || *str - 2 == ' ' || *str - 2 == '+' || *str
				- 2 == '0')
				f++;
			f += ft_parse(str, arg);
			if (f < 0)
			{
				ft_putstr_fd("\nErreur d'arguments !\n", 0);
				return ;
			}
			str += f;
		}
		str++;
	}
}

int	ft_printf(const char *form, ...)
{
	va_list	arg;

	va_start(arg, form);
	ft_display(form, arg);
	va_end(arg);
	return (0);
}
