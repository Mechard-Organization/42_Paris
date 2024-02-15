/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:04:31 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:12:57 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H
# include <commons.h>

typedef enum e_rettype
{
	SUCCESS,
	FAILURE
}		t_rettype;

void	ft_quicksort(double *tab, size_t size, int rev);
void	ft_putstr_fd(int fd, char const *s);
void	ft_strdel(char **as);
void	*ft_memcpy(void *s1, const void *s2, size_t n);
void	ft_putnbr(int fd, int n);

int		ft_min(int a, int b);
int		ft_max(int a, int b);
int		ft_strfind(char *s, int c);
int		ft_isnumber(char *str);
int		ft_nbrlen(long nbr);
int		ft_strcmp(char *s1, char *s2);
long	ft_atol(const char *str);
size_t	ft_strlen(const char *s);

char	*ft_itoa(int n);
char	*ft_strcpy(char *s1, const char *s2);
char	*ft_strncpy(char *s1, const char *s2, size_t n);
char	**ft_strsplit(char const *s, char c);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(int nb_str, ...);
char	*ft_strdup(char *src);

#endif