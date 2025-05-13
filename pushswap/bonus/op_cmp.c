/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_cmp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 11:17:06 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/12 14:54:20 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

int	ops_cmp(char *line, t_stacks *stacks)
{		
	if (ft_strcmp(line, "sa\n") == 0)
		sa(stacks->a, false);
	else if (ft_strcmp(line, "sb\n") == 0)
		sb(stacks->b, false);
	else if (ft_strcmp(line, "pa\n") == 0)
		pa(stacks, false);
	else if (ft_strcmp(line, "pb\n") == 0)
		pb(stacks, false);
	else if (ft_strcmp(line, "ra\n") == 0)
		ra(stacks->a, false);
	else if (ft_strcmp(line, "rb\n") == 0)
		rb(stacks->b, false);
	else if (ft_strcmp(line, "rr\n") == 0)
		rr(stacks, false);
	else if (ft_strcmp(line, "ss\n") == 0)
		ss(stacks, false);
	else
		return (1);
	return (0);
}

int	ops_cmp2(char *line, t_stacks *stacks)
{

	if (ft_strcmp(line, "rra\n") == 0)
		rra(stacks->a, false);
	else if (ft_strcmp(line, "rrb\n") == 0)
		rrb(stacks->b, false);
	else if (ft_strcmp(line, "rrr\n") == 0)
		rrr(stacks, false);
	else
		return (1);
	return (0);
}

int	check_operations(char *line, t_stacks *stacks)
{
	if(ft_strlens(line) > 4)
		return (1);
	else
	{
		if (ops_cmp(line, stacks) && ops_cmp2(line, stacks))
			return (1);
	}
	return (0);
}