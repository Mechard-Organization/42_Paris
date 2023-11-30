/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:31:48 by mechard           #+#    #+#             */
/*   Updated: 2023/11/30 19:19:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "./libft/libft.h"
# include <stdarg.h>
# include <stdio.h>

typedef struct s_printf
{
	int				len_flag;
	struct s_printf	*next;
}					t_printf;

typedef struct s_res
{
	char	*res;
	int		len;
	int		len_f;
}					t_res;

int					ft_printf(const char *str, ...);

char				*ft_convert_base(va_list arg, char *base);
char				*ft_convert_ui(va_list arg);

t_res				ft_parse(const char *str, int i, va_list arg);

#endif
