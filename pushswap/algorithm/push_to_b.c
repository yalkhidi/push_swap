/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:57:08 by codespace         #+#    #+#             */
/*   Updated: 2025/04/23 08:43:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	get_index(t_stack *stack, int value)
{
	t_node	*current;
	int		index;

	index = 0;
	current = stack->top;
	while (current)
	{
		if (current->value == value)
			return (index);
		current = current->next;
		index++;
	}
	return (-1);
}

int	find_insertion_b(t_stack *b, int value, t_data *data)
{
	t_node	*current;
	int		i;

	i = 0;
	current = b->top;
	if (value > data->b_max || value < data->b_min)
		return (get_index(b, data->b_max));
	while (current && current->next)
	{
		if (current->value > value && current->next->value < value)
			return (i + 1);
		current = current->next;
		i++;
	}
	return (0);
}
