/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:10:21 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:16:00 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <checker.h>

void	rotate(struct s_stack **stack)
{
	struct s_stack	*tmp;

	tmp = (*stack);
	while (tmp->next)
		tmp = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = (*stack);
	(*stack)->next->prev = NULL;
	tmp = (*stack)->next;
	(*stack)->next = NULL;
	(*stack) = tmp;
}

int	ra(t_all *all, int count)
{
	while (count)
	{
		if (all && all->a && all->a->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rotate(&all->a);
		}
		count--;
	}
	return (0);
}

int	rb(t_all *all, int count)
{
	while (count)
	{
		if (all && all->b && all->b->next)
		{
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
			rotate(&all->b);
		}
		count--;
	}
	return (0);
}

int	rr(t_all *all, int count)
{
	while (count)
	{
		if ((all && all->a && all->a->next) || (all && all->b && all->b->next))
			ft_putstr_fd(all->fd, (char *)__FUNCTION__);
		if (all && all->a && all->a->next)
			rotate(&all->a);
		if (all && all->b && all->b->next)
			rotate(&all->b);
		count--;
	}
	return (0);
}
