/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:18 by mechard           #+#    #+#             */
/*   Updated: 2025/02/01 14:23:17 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_msg(int code)
{
	if (code == 0)
		write(2, ERROR_NB_ARG, 172);
	else if (code == 1)
		write(2, ERROR_ALPH, 46);
	else if (code == 2)
		write(2, ERROR_0_PHILO, 36);
	else if (code == 3)
		write(2, ERROR_0_TTD, 31);
	else if (code == 4)
		write(2, ERROR_0_TTE, 31);
	else if (code == 5)
		write(2, ERROR_0_TTS, 33);
	else if (code == 6)
		write(2, ERROR_0_TMD, 33);
}

int	parse_error(char **argv)
{
	int		i;
	char	*p;

	i = 1;
	while (argv[i])
	{
		p = argv[i];
		while (*p)
		{
			if (!ft_isdigit(*p))
				return (1);
			p++;
		}
		i++;
	}
	return (0);
}
