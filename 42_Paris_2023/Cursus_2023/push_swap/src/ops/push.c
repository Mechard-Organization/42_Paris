/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:10:18 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:15:31 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	push(struct s_stack **stack_src, struct s_stack **stack_dest)
{
	ft_transfere_node_prev_np((t_pnp **)stack_src, (t_pnp **)stack_dest,
		(t_pnp *)*stack_src, (t_pnp *)*stack_dest);
}

int	pa(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			push(&all->b, &all->a);
		}
		count--;
	}
	return (0);
}

int	pb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			push(&all->a, &all->b);
		}
		count--;
	}
	return (0);
}
