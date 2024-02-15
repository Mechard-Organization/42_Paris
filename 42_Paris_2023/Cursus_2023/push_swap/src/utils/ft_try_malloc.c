/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_try_malloc.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:56:29 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:15:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	bytes;

	bytes = 0;
	while (bytes < len)
	{
		((char *)b)[bytes] = (unsigned char)c;
		bytes++;
	}
	return (b);
}

void	ft_try_free(void **mem)
{
	if (*mem)
	{
		free(*mem);
		*mem = NULL;
	}
}

void	*ft_try_malloc(size_t size)
{
	void	*new;

	new = malloc(size);
	if (!new)
	{
		write(2, MALLOC_ALLOCATION, ft_strlen(MALLOC_ALLOCATION));
		exit(-1);
	}
	ft_memset(new, 0, size);
	return (new);
}
