/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:18 by mechard           #+#    #+#             */
/*   Updated: 2024/07/18 16:57:01 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(const char *str)
{
	size_t	i;
	size_t	res;
	size_t	sign;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -sign;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + (str[i] - 48);
		i++;
	}
	return (res * sign);
}

t_philo	ft_parse_arg(int ac, char **av)
{
	t_philo	res;

	res.number_of_philo = ft_atoi(av[1]);
	res.time_to_die = ft_atoi(av[2]);
	res.time_to_eat = ft_atoi(av[3]);
	res.time_to_sleep = ft_atoi(av[4]);
	if (ac == 6)
		res.number_of_times_each_philosopher_must_eat = ft_atoi(av[5]);
	return (res);
}
