/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 14:28:38 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/04/23 09:49:02 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*build_stack(int ac, char **av)
{
	int		i;
	int		j;
	char	**splited;
	t_stack	*stack;

	i = ac;
	stack = create_stack();
	while (--i > 0)
	{
		j = 0;
		splited = ft_split(av[i]);
		while (splited[j])
			j++;
		while (--j >= 0)
		{
			push(stack, ft_atoi(splited[j]));
			if (!is_within_limits(stack->top->value))
				return (free_stack(stack), free_split(splited), NULL);
		}
		free_split(splited);
	}
	if (!check_dup(stack))
		return (NULL);
	return (stack);
}

t_stacks	*parse_a(int ac, char **av, t_stacks *stacks)
{
	if (ac == 1)
		exit(0);
	else if (!check_valid_chars(av) || !check_valid_operators(ac, av))
		print_message("Error\n");
	else
	{
		stacks = (t_stacks *)malloc(sizeof(t_stacks));
		if (!stacks)
			return (NULL);
		stacks->a = build_stack(ac, av);
		if (!stacks->a)
		{
			free(stacks);
			print_message("Error\n");
		}
		stacks->b = create_stack();
	}
	return (stacks);
}
