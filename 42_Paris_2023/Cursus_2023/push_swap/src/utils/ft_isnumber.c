/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 22:15:56 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:09:13 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <utils.h>

int	ft_isnumber(char *str)
{
	int	i;

	i = 0;
	if (str[0] == '-')
		i++;
	if (str[i] == 0)
		return (FAILURE);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '0')
			return (FAILURE);
		i++;
	}
	return (SUCCESS);
}
