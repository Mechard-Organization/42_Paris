/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 09:08:40 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:12:27 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <commons.h>
# define NUM "0123456789"
# define BUFF_SIZE_GNL 8192

typedef struct s_str
{
	char			*str;
	int				fd;
	struct s_str	*next;
}					t_str;

int					get_next_line(const int fd, char **line);

#endif