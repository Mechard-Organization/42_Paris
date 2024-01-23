/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 23:45:10 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:35:25 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	char	*tmp;

	tmp = (char *)s;
	while (len--)
		tmp[len] = (char)c;
	s = (void *)tmp;
	return (s);
}
