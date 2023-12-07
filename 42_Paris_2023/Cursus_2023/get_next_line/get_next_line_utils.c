/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 17:28:28 by mechard           #+#    #+#             */
/*   Updated: 2023/12/07 19:02:22 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	size_t	add;

	if (!dest || !src)
		return (NULL);
	add = 0;
	while (src[add] != '\0')
	{
		dest[add] = src[add];
		add++;
	}
	dest[add] = '\0';
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;

	if (!src)
		return (NULL);
	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	size_t	add;
	size_t	add2;

	if (!dest || !src)
		return (NULL);
	add = ft_strlen(dest);
	add2 = 0;
	while (src[add2] != '\0')
	{
		dest[add + add2] = src[add2];
		add2++;
	}
	dest[add + add2] = '\0';
	return (dest);
}

char	*ft_strchr(char *s, int c)
{
	char	*str;

	if (!s)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if ((char)c == *str)
			return (str);
		str++;
	}
	return (NULL);
}
