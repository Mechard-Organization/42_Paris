/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/10 11:15:47 by mechard           #+#    #+#             */
/*   Updated: 2024/01/16 14:36:09 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	char			*str;
	unsigned int	counter;

	str = (char *)s;
	if (str && f)
	{
		counter = 0;
		while (str[counter])
		{
			(*f)(counter, &str[counter]);
			counter++;
		}
	}
}
