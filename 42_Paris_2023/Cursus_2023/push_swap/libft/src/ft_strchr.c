/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 16:34:29 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:35:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] == (unsigned char)c % 256)
			return ((char *)s + i);
	if ((unsigned char)c == '\0' && s[i] == '\0')
		return ((char *)s + i);
	return (0);
}
