/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   marks_handle.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mechard <mechard@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 13:11:53 by mechard           #+#    #+#             */
/*   Updated: 2024/02/15 14:09:32 by mechard          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <commons.h>
#include <push_swap.h>

// is the stack contain only marked values
int	only_marks(t_stack *s)
{
	while (s)
	{
		if (s->mark == OFF)
			return (FAILURE);
		s = s->next;
	}
	return (SUCCESS);
}

static int	set_k(t_stack *s)
{
	t_stack	*tmp;
	int		last;
	int		k;

	k = 1;
	tmp = s->next;
	last = s->value;
	while (tmp)
	{
		if (tmp->value > last)
		{
			k++;
			last = tmp->value;
		}
		else
			tmp = tmp->next;
	}
	return (k);
}

t_marks_ret	get_best_mark(t_stack *s)
{
	t_marks_ret	ret;
	t_stack		*best;
	int			kbest;
	int			k;

	kbest = 0;
	while (s)
	{
		k = set_k(s);
		if (k > kbest)
		{
			best = s;
			kbest = k;
		}
		s = s->next;
	}
	ret.s = best;
	ret.n = kbest;
	return (ret);
}

// return the number of mark in the best configuration
int	get_best_mark_count(t_stack *s)
{
	t_marks_ret	ret;

	ret = get_best_mark(s);
	return (ret.n);
}

// return first stack node with a mark in the best configuration
t_stack	*get_best_mark_start(t_stack *s)
{
	t_marks_ret	ret;

	ret = get_best_mark(s);
	return (ret.s);
}
