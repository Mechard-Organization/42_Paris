/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:10:49 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:16:30 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	swap(struct s_stack **stack)
{
	ft_swap_node_np((t_pnp **)stack, (t_pnp *)(*stack),
		(t_pnp *)(*stack)->next);
}

int	sa(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a && all->a->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			swap(&all->a);
		}
		count--;
	}
	return (0);
}

int	sb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b && all->b->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			swap(&all->b);
		}
		count--;
	}
	return (0);
}

int	ss(t_all *all, int count)
{
	while (count)
	{
		if ((all && all->a && all->a->next) || (all && all->b && all->b->next))
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
		if (all && all->a && all->a->next)
			swap(&all->a);
		if (all && all->b && all->b->next)
			swap(&all->b);
		count--;
	}
	return (0);
}
