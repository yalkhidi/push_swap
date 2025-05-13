/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/27 17:27:49 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/23 07:22:47 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	pa(t_stacks *stacks, bool print)
{
	int	peek_val;

	if (stacks->b->size > 0)
	{
		peek_val = peek(stacks->b);
		push(stacks->a, peek_val);
		pop(stacks->b);
	}
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stacks *stacks, bool print)
{
	int	peek_val;

	if (stacks->a->size > 0)
	{
		peek_val = peek(stacks->a);
		push(stacks->b, peek_val);
		pop(stacks->a);
	}
	if (print)
		write(1, "pb\n", 3);
}
