/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:17 by mechard           #+#    #+#             */
/*   Updated: 2023/11/21 15:26:43 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_display(const char *str, va_list arg)
{
	while (*str)
	{
		if (*str != '%')
			ft_putchar_fd(*str, 0);
		else
		{
			if (ft_parse(str, arg) == -1)
			{
				ft_putstr_fd("\nErreur d'arguments !\n", 0);
				return ;		
			}
			str += ft_parse(str, arg);
		}
		str++;
	}
}

int	ft_printf(const char *form, ...)
{
	va_list arg;

	va_start(arg, form);
	ft_display(form, arg);
	va_end(arg);
	return (0);
}