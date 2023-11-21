/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:17 by mechard           #+#    #+#             */
/*   Updated: 2023/11/20 15:41:18 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdio.h>

void	ft_display(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '%')
		ft_putchar_fd(str[i], 0);
}

int	ft_printf(const char *form, ...)
{
	va_list arg;

	va_start(arg, form);
	va_arg(arg, const char *);
	ft_display((char *)form);
	va_end(arg);
	return (0);
}