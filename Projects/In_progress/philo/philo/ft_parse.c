/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 16:04:18 by mechard           #+#    #+#             */
/*   Updated: 2024/12/12 14:35:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_atoi(const char *str)
{
	size_t	index;
	size_t	result;
	size_t	sign;

	index = 0;
	sign = 1;
	result = 0;
	while (str[index] == ' ' || (str[index] >= '\t' && str[index] <= '\r'))
		index++;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -sign;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		result = result * 10 + (str[index] - '0');
		index++;
	}
	return (result * sign);
}

int	ft_isnum(char **arguments, int inner_index, int outer_index)
{
	while (arguments[outer_index])
	{
		while (arguments[outer_index][inner_index])
		{
			if (arguments[outer_index][inner_index] < '0'
				|| arguments[outer_index][inner_index] > '9'
				|| ft_strlen(arguments[outer_index]) > 10)
				return (0);
			inner_index++;
		}
		inner_index = 0;
		outer_index++;
	}
	return (1);
}

int	ft_parse(int argument_count, char **arguments, t_p *params)
{
	if ((argument_count == 5 || argument_count == 6) && ft_isnum(arguments, 0,
			1))
	{
		params->a.total = ft_atoi(arguments[1]);
		params->a.die = ft_atoi(arguments[2]);
		params->a.eat = ft_atoi(arguments[3]);
		params->a.sleep = ft_atoi(arguments[4]);
		params->a.m_eat = -1;
		if (argument_count == 6)
			params->a.m_eat = ft_atoi(arguments[5]);
		if (params->a.total <= 0 || params->a.die <= 0 || params->a.eat <= 0
			|| params->a.sleep <= 0)
			return (0);
		return (1);
	}
	return (0);
}

void	init_mutex(t_p *params)
{
	pthread_mutex_init(&params->a.write_mutex, NULL);
	pthread_mutex_init(&params->a.dead, NULL);
	pthread_mutex_init(&params->a.time_eat, NULL);
	pthread_mutex_init(&params->a.finish, NULL);
}

int	initialize(t_p *params)
{
	int	index;

	index = 0;
	params->a.start_t = actual_time();
	params->a.stop = 0;
	params->a.nb_p_finish = 0;
	init_mutex(params);
	while (index < params->a.total)
	{
		params->ph[index].id = index + 1;
		params->ph[index].ms_eat = params->a.start_t;
		params->ph[index].nb_eat = 0;
		params->ph[index].finish = 0;
		params->ph[index].r_f = NULL;
		pthread_mutex_init(&params->ph[index].l_f, NULL);
		if (params->a.total == 1)
			return (1);
		if (index == params->a.total - 1)
			params->ph[index].r_f = &params->ph[0].l_f;
		else
			params->ph[index].r_f = &params->ph[index + 1].l_f;
		index++;
	}
	return (1);
}
