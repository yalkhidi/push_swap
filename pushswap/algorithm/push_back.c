/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_back.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/23 07:42:29 by codespace         #+#    #+#             */
/*   Updated: 2025/04/23 07:46:15 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	find_insertion_a(t_stack *a, int value)
{
	t_node	*current;
	int		i;
	int		min;
	int		max;

	current = a->top;
	i = 0;
	min = get_min(a);
	max = get_max(a);
	if (value < min || value > max)
		return (get_index(a, min));
	while (current && current->next)
	{
		if (current->value < value && current->next->value > value)
			return (i + 1);
		current = current->next;
		i++;
	}
	return (0);
}

void	push_back_to_a(t_stacks *stacks)
{
	int	index;
	int	min_index;

	while (stacks->b->size > 0)
	{
		index = find_insertion_a(stacks->a, stacks->b->top->value);
		rotate_to_index(stacks->a, index, 'a');
		pa(stacks, true);
	}
	min_index = get_index(stacks->a, get_min(stacks->a));
	rotate_to_index(stacks->a, min_index, 'a');
}
