/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 14:34:06 by mechard           #+#    #+#             */
/*   Updated: 2024/12/18 15:57:40 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/*________________LIBRARIES_______________*/

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

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

typedef struct s_arg
{
	int						total;
	int						die;
	int						eat;
	int						sleep;
	int						m_eat;
	long int				start_t;
	pthread_mutex_t			write_mutex;
	pthread_mutex_t			dead;
	pthread_mutex_t			time_eat;
	pthread_mutex_t			finish;
	int						nb_p_finish;
	int						stop;
}							t_arg;

typedef struct s_philo
{
	int						id;
	pthread_t				thread_id;
	pthread_t				thread_death_id;
	pthread_mutex_t			*r_f;
	pthread_mutex_t			l_f;
	t_arg					*pa;
	long int				ms_eat;
	unsigned int			nb_eat;
	int						finish;
}							t_philo;

typedef struct s_p
{
	t_philo					*ph;
	t_arg					a;
}							t_p;

/*_______________FUNCTIONS________________*/

int				ft_parse(int argc, char **argv, t_p *p);
int				initialize(t_p *p);
int				ft_exit(char *str);
int				check_death(t_philo *ph, int i);
int				threading(t_p *p);
long int		actual_time(void);
size_t			ft_strlen(const char *s);

void			write_status(char *str, t_philo *ph);
void			ft_putstr_fd(char *s, int fd);
void			ft_usleep(long int time_in_ms);
void			ft_state(t_philo *ph);

#endif