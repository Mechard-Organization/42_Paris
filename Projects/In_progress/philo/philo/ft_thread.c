/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:19 by mechard@stu       #+#    #+#             */
/*   Updated: 2024/12/12 14:46:45 by mechard          ###   ########.fr       */
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
	pthread_mutex_unlock(&philosopher->pa->time_eat);
	pthread_mutex_unlock(&philosopher->pa->finish);
	return (NULL);
}

void	*thread(void *data)
{
	t_philo	*philosopher;

	philosopher = (t_philo *)data;
	if (philosopher->id % 2 == 0)
		ft_usleep(philosopher->pa->eat / 10);
	while (!check_death(philosopher, 0))
	{
		pthread_create(&philosopher->thread_death_id, NULL, is_dead, data);
		ft_state(philosopher);
		pthread_detach(philosopher->thread_death_id);
		if ((int)++philosopher->nb_eat == philosopher->pa->m_eat)
		{
			pthread_mutex_lock(&philosopher->pa->finish);
			philosopher->finish = 1;
			philosopher->pa->nb_p_finish++;
			if (philosopher->pa->nb_p_finish == philosopher->pa->total)
			{
				pthread_mutex_unlock(&philosopher->pa->finish);
				return (check_death(philosopher, 2), NULL);
			}
			return (pthread_mutex_unlock(&philosopher->pa->finish), NULL);
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
