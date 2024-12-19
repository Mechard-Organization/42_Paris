/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:19 by mechard@stu       #+#    #+#             */
/*   Updated: 2024/12/18 15:54:51 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*is_dead(void *data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)data;
	ft_usleep(philosopher->pa->die + 1);
	pthread_mutex_lock(&philosopher->pa->time_eat);
	pthread_mutex_lock(&philosopher->pa->finish);
	if (!check_death(philosopher, 0) && !philosopher->finish && ((actual_time()
				- philosopher->ms_eat) >= (long)(philosopher->pa->die)))
	{
		pthread_mutex_unlock(&philosopher->pa->time_eat);
		pthread_mutex_unlock(&philosopher->pa->finish);
		pthread_mutex_lock(&philosopher->pa->write_mutex);
		write_status("died\n", philosopher);
		pthread_mutex_unlock(&philosopher->pa->write_mutex);
		check_death(philosopher, 1);
	}
	else
	{
		pthread_mutex_unlock(&philosopher->pa->time_eat);
		pthread_mutex_unlock(&philosopher->pa->finish);
	}
	return (NULL);
}

void	*thread(void *data, int nb_philo)
{
	t_philo	*phil;

	phil = (t_philo *)data;
	pthread_mutex_lock(&phil->pa->write_mutex);
	write_status("is thinking\n", phil);
	pthread_mutex_unlock(&phil->pa->write_mutex);
	if (phil->id % 2 == 0)
		ft_usleep(phil->pa->eat / 10);
	while (!check_death(phil, 0))
	{
		pthread_create(&phil->thread_death_id, NULL, is_dead, data);
		(ft_state(phil), pthread_detach(phil->thread_death_id));
		if ((int)++phil->nb_eat == phil->pa->m_eat)
		{
			(pthread_mutex_lock(&phil->pa->finish), phil->finish = 1);
			phil->pa->nb_p_finish++;
			if (phil->pa->nb_p_finish == phil->pa->total)
				return (pthread_mutex_unlock(&phil->pa->finish),
					check_death(phil, 2), NULL);
			return (pthread_mutex_unlock(&phil->pa->finish), NULL);
		}
	}
	return (NULL);
}

int	threading(t_p *params)
{
	int	index;

	index = 0;
	while (index < params->a.total)
	{
		params->ph[index].pa = &params->a;
		if (pthread_create(&params->ph[index].thread_id, NULL, thread,
				&params->ph[index]) != 0)
			return (ft_exit("Pthread did not return (0\n"));
		index++;
	}
	return (1);
}
