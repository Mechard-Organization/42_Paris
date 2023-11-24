/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:48 by mechard           #+#    #+#             */
/*   Updated: 2023/11/24 14:55:31 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct	s_printf
{
	int					len_flag;
	struct s_printf		*next;
}						t_printf;

int		ft_printf(const char *, ...);
int		ft_parse(const char *str, va_list arg);

char	*ft_convert_base(va_list arg, char *base);
char	*ft_convert_ui(va_list arg);

#endif