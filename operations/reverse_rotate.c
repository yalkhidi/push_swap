/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 09:21:43 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/23 07:24:33 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rra(t_stack *a, bool print)
{
	t_node	*prev;
	t_node	*last;

	if (a->size >= 2)
	{
		prev = NULL;
		last = a->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = a->top;
		a->top = last;
		if (print)
			write(1, "rra\n", 4);
	}
	else
		return ;
}

void	rrb(t_stack *b, bool print)
{
	t_node	*prev;
	t_node	*last;

	if (b->size >= 2)
	{
		prev = NULL;
		last = b->top;
		while (last->next)
		{
			prev = last;
			last = last->next;
		}
		prev->next = NULL;
		last->next = b->top;
		b->top = last;
		if (print)
			write(1, "rrb\n", 4);
	}
	else
		return ;
}

void	rrr(t_stacks *stacks, bool print)
{
	rra(stacks->a, false);
	rrb(stacks->b, false);
	if (print)
		write(1, "rrr\n", 4);
}
