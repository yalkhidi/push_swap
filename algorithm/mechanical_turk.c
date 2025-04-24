/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mechanical_turk.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 10:50:51 by codespace         #+#    #+#             */
/*   Updated: 2025/04/23 08:42:34 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	mechanical_turk(t_stacks *stacks)
{
	t_data	best;

	pb(stacks, true);
	pb(stacks, true);
	if (stacks->a->size >= 3)
	{
		while (stacks->a->size > 3)
		{
			calculate(stacks, &best);
			execute_moves(stacks, best);
		}
		sort_three(stacks->a);
	}
	push_back_to_a(stacks);
}
