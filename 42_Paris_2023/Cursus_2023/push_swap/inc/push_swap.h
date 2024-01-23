/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 14:54:11 by mechard           #+#    #+#             */
/*   Updated: 2024/01/19 19:15:52 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/inc/libft.h"

int		*ft_sort(int *a);
int		*move_sa(int *a);
int		*move_sb(int *b);
int		*move_ss(int *a, int *b);
int		*move_pa(int *a);
int		*move_pb(int *b);
int		*move_ra(int *a);
int		*move_rb(int *b);
int		*move_rr(int *a, int *b);
int		*move_rra(int *a);
int		*move_rrb(int *b);
int		*move_rrr(int *a, int *b);

int		main(int ac, char **av);

#endif