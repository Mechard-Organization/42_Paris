/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:06 by mechard           #+#    #+#             */
/*   Updated: 2024/07/19 15:46:14 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*________________LIBRARIES_______________*/

# include <stdint.h>
# include <sys/types.h>
# include <unistd.h>

/*_______________MSGS_ERROR_______________*/

# ifndef ERROR_SET
#  define ERROR_SET "\033[1;31m\nERROR !\033[0m Une variable ne \
s'estt pas initialise correctement !"
# endif

# ifndef INVALID_NB_ARGS
#  define INVALID_NB_ARGS "\033[1;31m\nERROR !\033[0m Le nombre \
d'arguments est invalide !\n\n\033[1m\033[1;33m./philo number_of\
_philosophers time_to_die time_to_eat time_to_sleep [number_of_t\
imes_each_philosopher_must_eat]\033[0m\n\n"
# endif

/*_______________STRUCTURES_______________*/

/*Structure for parse data of philosophers. The last argument is optionnal.
  RTFNV !*/

typedef struct s_philos
{
	size_t	number_of_philo;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	size_t	number_of_times_eat;
}			t_philos;

/*_______________FUNCTIONS________________*/

size_t		ft_strlen(const char *s);

t_philos	ft_parse_arg(int ac, char **av);

void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(size_t n, int fd);

#endif