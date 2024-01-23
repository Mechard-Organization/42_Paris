/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 00:02:30 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:34:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*tmp_dst;
	char	*tmp_src;

	if (!dst && !src)
		return (NULL);
	tmp_dst = (char *)dst;
	tmp_src = (char *)src;
	while (n--)
		tmp_dst[n] = tmp_src[n];
	dst = (void *)tmp_dst;
	return (dst);
}
