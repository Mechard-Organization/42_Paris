/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_3439.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 16:16:19 by mechard           #+#    #+#             */
/*   Updated: 2024/03/04 16:16:47 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_del_3439(char *str)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	j = 0;
	tmp = ft_calloc(ft_strlen(str) + 1, sizeof(char));
	if (!tmp)
		return (NULL);
	while (str[i + 1])
	{
		if ((i == 0 || (size_t)i == (ft_strlen(str) - 1)) && str[i] == 34)
			i++;
		tmp[j++] = str[i++];
	}
	if (tmp[j] != '\0')
		return (NULL);
	return (tmp);
}