/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_rotations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:55:32 by codespace         #+#    #+#             */
/*   Updated: 2025/04/23 09:56:26 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate_to_index(t_stack *stack, int index, char name)
{
	int	count;

	count = 0;
	if (index <= stack->size / 2)
	{
		while (index-- > 0)
		{
			if (name == 'a')
				ra(stack, true);
			else
				rb(stack, true);
		}
	}
	else
	{
		count = stack->size - index;
		while (count-- > 0)
		{
			if (name == 'a')
				rra(stack, true);
			else
				rrb(stack, true);
		}
	}
}

void	execute_rr(t_stacks *stacks, int a_rot, int b_rot)
{
	while (a_rot > 0 && b_rot > 0)
	{
		rr(stacks, true);
		a_rot--;
		b_rot--;
	}
	while (a_rot > 0)
	{
		ra(stacks->a, true);
		a_rot--;
	}
	while (b_rot > 0)
	{
		rb(stacks->b, true);
		b_rot--;
	}
}

void	execute_rrr(t_stacks *stacks, int a_rot, int b_rot)
{
	a_rot = stacks->a->size - a_rot;
	b_rot = stacks->b->size - b_rot;
	while (a_rot > 0 && b_rot > 0)
	{
		rrr(stacks, true);
		a_rot--;
		b_rot--;
	}
	while (a_rot > 0)
	{
		rra(stacks->a, true);
		a_rot--;
	}
	while (b_rot > 0)
	{
		rrb(stacks->b, true);
		b_rot--;
	}
}

void	execute_moves(t_stacks *stacks, t_data data)
{
	int	a_rot;
	int	b_rot;

	a_rot = data.a_index;
	b_rot = data.b_index;
	if (a_rot <= stacks->a->size / 2 && b_rot <= stacks->b->size / 2)
		execute_rr(stacks, a_rot, b_rot);
	else if (a_rot > stacks->a->size / 2 && b_rot > stacks->b->size / 2)
		execute_rrr(stacks, a_rot, b_rot);
	else
	{
		rotate_to_index(stacks->a, data.a_index, 'a');
		rotate_to_index(stacks->b, data.b_index, 'b');
	}
	pb(stacks, true);
}
