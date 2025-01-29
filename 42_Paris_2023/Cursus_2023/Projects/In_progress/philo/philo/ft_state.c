/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:45:04 by mechard@stu       #+#    #+#             */
/*   Updated: 2024/12/12 15:17:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	write_status(char *status_message, t_philo *philosopher)
{
	long int	current_time;

	current_time = -1;
	current_time = actual_time() - philosopher->pa->start_t;
	if (current_time >= 0 && current_time <= 2147483647
		&& !check_death(philosopher, 0))
	{
		printf("%ld ", current_time);
		printf("Philosopher %d %s", philosopher->id, status_message);
	}
}

void	sleep_think(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->pa->write_mutex);
	write_status("is sleeping\n", philosopher);
	pthread_mutex_unlock(&philosopher->pa->write_mutex);
	ft_usleep(philosopher->pa->sleep);
	pthread_mutex_lock(&philosopher->pa->write_mutex);
	write_status("is thinking\n", philosopher);
	pthread_mutex_unlock(&philosopher->pa->write_mutex);
}

void	ft_state(t_philo *philosopher)
{
	pthread_mutex_lock(&philosopher->l_f);
	pthread_mutex_lock(&philosopher->pa->write_mutex);
	write_status("has taken a fork\n", philosopher);
	pthread_mutex_unlock(&philosopher->pa->write_mutex);
	if (!philosopher->r_f)
	{
		ft_usleep(philosopher->pa->die * 2);
		return ;
	}
	pthread_mutex_lock(philosopher->r_f);
	pthread_mutex_lock(&philosopher->pa->write_mutex);
	write_status("has taken a fork\n", philosopher);
	pthread_mutex_unlock(&philosopher->pa->write_mutex);
	pthread_mutex_lock(&philosopher->pa->write_mutex);
	write_status("is eating\n", philosopher);
	pthread_mutex_lock(&philosopher->pa->time_eat);
	philosopher->ms_eat = actual_time();
	pthread_mutex_unlock(&philosopher->pa->time_eat);
	pthread_mutex_unlock(&philosopher->pa->write_mutex);
	ft_usleep(philosopher->pa->eat);
	pthread_mutex_unlock(philosopher->r_f);
	pthread_mutex_unlock(&philosopher->l_f);
	sleep_think(philosopher);
}
