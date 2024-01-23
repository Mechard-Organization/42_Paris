/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 11:50:33 by abutet            #+#    #+#             */
/*   Updated: 2024/01/16 14:33:55 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	tmp;
	void	*r;

	if (!nmemb || !size)
		return (malloc(0));
	if (SIZE_MAX / nmemb < size)
	{
		return (NULL);
	}
	tmp = nmemb * size;
	r = malloc(tmp);
	if (!r)
		return (0);
	ft_bzero(r, tmp);
	return (r);
}
