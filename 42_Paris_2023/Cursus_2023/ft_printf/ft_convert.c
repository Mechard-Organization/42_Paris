/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 13:59:05 by mechard           #+#    #+#             */
/*   Updated: 2023/11/30 19:19:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_print_add(va_list arg)
{
	unsigned long long	convert;
	char				*base;
	char				*res_hex;
	size_t				i;
	size_t				len;

	convert = (unsigned long long)va_arg(arg, unsigned long long);
	if (convert == 0)
		return ("(nil)");
	i = ft_nbrlen(convert, 16) + 1;
	len = i;
	base = "0123456789abcdef";
	res_hex = (char *)malloc(sizeof(char) * 20);
	while ((convert / 16) > 0 || i > 0)
	{
		res_hex[i] = base[(convert % 16)];
		convert /= 16;
		i--;
	}
	res_hex[i] = base[(convert % 16)];
	res_hex[0] = '0';
	res_hex[1] = 'x';
	res_hex[(len + 3)] = '\0';
	return (res_hex);
}

char	*ft_convert_ui(va_list arg)
{
	char			*res;
	unsigned int	ui;

	ui = (int)va_arg(arg, int);
	res = ft_itoa(ui);
	return (res);
}

char	*ft_set_alph(char *base)
{
	if (ft_strcmp(base, "HEX") == 0)
		return ("0123456789ABCDEF");
	return ("0123456789abcdef");
}

char	*ft_convert_hex(va_list arg, char *base)
{
	int		convert;
	char	*alph;
	char	*res_hex;
	size_t	i;
	size_t	len;

	convert = (int)va_arg(arg, int);
	if (convert == 0)
		return (ft_strdup("(nil)"));
	i = ft_nbrlen(convert, 16);
	len = i;
	alph = ft_set_alph(base);
	res_hex = (char *)malloc(sizeof(char) * len);
	if (!res_hex)
		return (NULL);
	(void)base;
	while (i-- > 0)
	{
		res_hex[i] = alph[(convert % 16)];
		convert /= 16;
	}
	res_hex[i] = alph[(convert % 16)];
	res_hex[(len + 1)] = '\0';
	return (res_hex);
}

char	*ft_convert_base(va_list arg, char *base)
{
	if (ft_strcmp(base, "add") == 0)
		return (ft_print_add(arg));
	else if (ft_strcmp(base, "Dec") == 0)
		return (ft_convert_ui(arg));
	else if (ft_strcmp(base, "hex") == 0 || ft_strcmp(base, "HEX") == 0)
		return (ft_convert_hex(arg, base));
	return (NULL);
}
