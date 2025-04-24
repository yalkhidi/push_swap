/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cost_calculation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 19:51:29 by codespace         #+#    #+#             */
/*   Updated: 2025/04/23 08:46:51 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_rotation_cost(int size, int index)
{
	if (index <= size / 2)
		return (index);
	else
		return (size - index);
}

int	get_total_cost(t_stacks *stacks, int a_index, int value, t_data *data)
{
	int	b_index;
	int	cost_a;
	int	cost_b;

	b_index = find_insertion_b(stacks->b, value, data);
	cost_a = get_rotation_cost(stacks->a->size, a_index);
	cost_b = get_rotation_cost(stacks->b->size, b_index);
	return (cost_a + cost_b);
}

void	update_data(t_data *best, int total, int a_index, int b_index)
{
	best->total = total;
	best->a_index = a_index;
	best->b_index = b_index;
}

void	calculate(t_stacks *stacks, t_data *data)
{
	t_node	*current;
	int		a_index;
	int		b_index;
	int		total;

	a_index = 0;
	current = stacks->a->top;
	data->total = 2147483647;
	set_min_max(stacks->b, data);
	while (current)
	{
		b_index = find_insertion_b(stacks->b, current->value, data);
		total = get_total_cost(stacks, a_index, current->value, data);
		if (total < data->total)
			update_data(data, total, a_index, b_index);
		current = current->next;
		a_index++;
	}
}
