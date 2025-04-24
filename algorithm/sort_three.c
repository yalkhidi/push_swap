/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:26:55 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/23 08:33:09 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted(t_stack *stack)
{
	t_node	*nodes;

	nodes = stack->top;
	while (nodes->next)
	{
		if (nodes->value > nodes->next->value)
			return (false);
		nodes = nodes->next;
	}
	return (true);
}

void	sort_three(t_stack *stack)
{
	int	first;
	int	middle;
	int	last;

	first = peek(stack);
	middle = stack->top->next->value;
	last = stack->top->next->next->value;
	if (first > middle && middle < last && last > first)
		sa(stack, true);
	else if (first > middle && middle < last && last < first)
		ra(stack, true);
	else if (first < middle && middle > last && last < first)
		rra(stack, true);
	else if (first > middle && middle > last && last < first)
	{
		sa(stack, true);
		rra(stack, true);
	}
	else if (first < middle && middle > last && last > first)
	{
		sa(stack, true);
		ra(stack, true);
	}
}
