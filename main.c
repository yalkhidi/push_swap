/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 10:14:57 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/24 10:13:53 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stacks	*stacks;

	stacks = NULL;
	stacks = parse_a(ac, av, stacks);
	if (is_sorted(stacks->a))
	{
		free_stack(stacks->a);
		free_stack(stacks->b);
		free(stacks);
		exit(0);
	}
	if (stacks->a->size == 3)
		sort_three(stacks->a);
	else if (stacks->a->size < 3)
	{
		if (!is_sorted(stacks->a))
			sa(stacks->a, true);
	}
	else
		mechanical_turk(stacks);
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
}
