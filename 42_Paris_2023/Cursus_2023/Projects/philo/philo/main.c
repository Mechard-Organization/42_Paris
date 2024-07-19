/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:09 by mechard           #+#    #+#             */
/*   Updated: 2024/07/19 15:44:34 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_philos	philo;

	if (ac < 5 || ac > 6)
		return (ft_putstr_fd(INVALID_NB_ARGS, 1), 1);
	philo = ft_parse_arg(ac, av);
	ft_putstr_fd("Number.s ofphilo.s = ", 1);
	ft_putnbr_fd(philo.number_of_philo, 1);
	ft_putstr_fd("\nTime to die = ", 1);
	ft_putnbr_fd(philo.time_to_die, 1);
	ft_putstr_fd("\nTime to eat = ", 1);
	ft_putnbr_fd(philo.time_to_eat, 1);
	ft_putstr_fd("\nTime to sleep = ", 1);
	ft_putnbr_fd(philo.time_to_sleep, 1);
	if (ac == 6)
	{
		ft_putstr_fd("\nNumber of times each philosopher must eat = ", 1);
		ft_putnbr_fd(philo.number_of_times_eat, 1);
	}
	return (0);
}
