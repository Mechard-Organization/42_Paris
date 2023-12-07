/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:28:31 by mechard           #+#    #+#             */
/*   Updated: 2023/12/07 19:33:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strjoinf(char *s1, char *s2)
{
	char	*ret;

	ret = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!ret)
		return (NULL);
	ft_strcpy(ret, s1);
	ft_strcat(ret, s2);
	free((char *)s1);
	return (ret);
}

static int	ft_read_line(int fd, char **buf, char **line, char *pos)
{
	int	result;

	*line = ft_strdup(*buf);
	result = 0;
	while (!pos && result >= 0)
	{
		result = read(fd, *buf, BUFF_SIZE);
		pos = ft_strchr(*buf, '\n');
		if (!pos && !result)
			return ((*buf)[0] = 0);
		(*buf)[result] = 0;
		if (pos)
			pos[0] = 0;
		*line = ft_strjoinf(*line, *buf);
		if (pos)
			ft_strcpy(*buf, pos + 1);
		else
		{
			*line = ft_strjoinf(*line, *buf);
			(*buf)[0] = 0;
		}
	}
	if (*line)
		return (1);
	return (-1);
}

char	*ft_result(int result, char *line, char *buf)
{
	if (result == 0 && !*line)
	{
		free(buf);
		return (NULL);
	}
	if (result == -1)
		return (NULL);
	if (result || ft_strlen(line) != 0)
		return (line);
	return (NULL);
}

char	*get_next_line(int const fd)
{
	static char	*buf;
	char		*pos;
	char		*line;
	int			result;

	if (BUFF_SIZE < 1)
		return (NULL);
	buf = (char *)malloc(sizeof(char) * (BUFF_SIZE + 1));
	if (!buf)
		return (NULL);
	pos = ft_strchr(buf, '\n');
	if (pos)
	{
		*pos = 0;
		line = ft_strdup(buf);
		ft_strcpy(buf, pos + 1);
		return (line);
	}
	result = ft_read_line(fd, &buf, &line, NULL);
	return (ft_result(result, line, buf));
}
