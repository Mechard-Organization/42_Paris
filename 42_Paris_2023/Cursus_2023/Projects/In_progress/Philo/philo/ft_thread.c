/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_thread.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 19:42:19 by mechard@stu       #+#    #+#             */
/*   Updated: 2025/02/01 15:29:06 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	dead_check(t_philo *philo)
{
	int	dead;

	pthread_mutex_lock(philo->dead_lock);
	dead = *philo->dead;
	pthread_mutex_unlock(philo->dead_lock);
	return (dead);
}

void	*philo_routine(void *data)
{
	t_philo	*philo;

	philo = (t_philo *)data;
	if (philo->id % 2 == 0 || (philo->num_of_philos % 2 == 1
			&& philo->id == philo->num_of_philos))
		ft_thinking(philo);
	while (!dead_check(philo))
	{
		ft_eating(philo);
		ft_sleeping(philo);
		ft_thinking(philo);
	}
	return (data);
}

int	thread_create(t_principal *principal)
{
	pthread_t	observer;
	int			i;

	i = -1;
	if (pthread_create(&observer, NULL, &monitor, principal->philos) != 0)
		destory_all(ERROR_C_THREAD, principal);
	while (++i < principal->philos[0].num_of_philos)
	{
		if (pthread_create(&principal->philos[i].thread, NULL, &philo_routine,
				&principal->philos[i]) != 0)
			destory_all(ERROR_C_THREAD, principal);
	}
	i = -1;
	if (pthread_join(observer, NULL) != 0)
		destory_all(ERROR_J_THREAD, principal);
	while (++i < principal->philos[0].num_of_philos)
	{
		if (pthread_join(principal->philos[i].thread, NULL) != 0)
			destory_all(ERROR_J_THREAD, principal);
	}
	return (0);
}
