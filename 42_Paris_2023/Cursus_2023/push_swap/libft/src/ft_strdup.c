/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:30:20 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:36:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

char	*ft_strdup(const char *src)
{
	char	*dest;

	dest = (char *)malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (!dest)
		return (NULL);
	dest = ft_strcpy(dest, src);
	return (dest);
}
