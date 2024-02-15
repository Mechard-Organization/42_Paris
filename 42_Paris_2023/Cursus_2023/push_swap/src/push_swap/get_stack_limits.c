/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_stack_limits.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:11:28 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:14:26 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

t_stack	*get_stack_min(t_stack *s)
{
	t_stack	*ret;
	int		min;

	ret = s;
	if (s)
		min = s->value;
	while (s)
	{
		if (s->value < min)
		{
			ret = s;
			min = s->value;
		}
		s = s->next;
	}
	return (ret);
}

t_stack	*get_stack_max(t_stack *s)
{
	t_stack	*ret;
	int		max;

	ret = s;
	if (s)
		max = s->value;
	while (s)
	{
		if (s->value > max)
		{
			ret = s;
			max = s->value;
		}
		s = s->next;
	}
	return (ret);
}
