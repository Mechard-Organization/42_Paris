/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:53:26 by mechard@stu       #+#    #+#             */
/*   Updated: 2024/12/05 15:13:59 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	check_death(t_philo *philosopher, int flag)
{
	pthread_mutex_lock(&philosopher->pa->dead);
	if (flag)
		philosopher->pa->stop = flag;
	if (philosopher->pa->stop)
	{
		pthread_mutex_unlock(&philosopher->pa->dead);
		return (1);
	}
	pthread_mutex_unlock(&philosopher->pa->dead);
	return (0);
}

long int	actual_time(void)
{
	long int		current_time;
	struct timeval	time_value;

	current_time = 0;
	if (gettimeofday(&time_value, NULL) == -1)
		ft_exit("Gettimeofday returned -1\n");
	current_time = (time_value.tv_sec * 1000) + (time_value.tv_usec / 1000);
	return (current_time);
}

void	ft_usleep(long int time_in_ms)
{
	long int	start_time;

	start_time = 0;
	start_time = actual_time();
	while ((actual_time() - start_time) < time_in_ms)
		usleep(time_in_ms / 10);
}
