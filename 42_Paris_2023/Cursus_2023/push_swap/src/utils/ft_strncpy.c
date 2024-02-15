/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:23:07 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:07:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

char	*ft_strncpy(char *dest, const char *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len && src[i] != '\0')
		dest[i] = src[i++];
	while (i < len)
		dest[i++] = '\0';
	return (dest);
}
