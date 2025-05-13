/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 07:24:59 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/12 15:02:11 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"
#include <stdio.h>

void print_stack(t_stack *a)
{
	t_node *current;

	current = a->top;
	while(current)
	{
		printf("%ld", current->value);
		if(current->next != NULL)
			printf(",");
		current = current->next;
	}
	printf("\n");
}

void	read_ops(t_stacks *stacks)
{
	char		*line;
	// int			a_size;

	// a_size = stacks->a->size;
	line = get_next_line(0);
	while(line)
	{
		if (check_operations(line, stacks) == 1)
		{
			
			free_stack(stacks->a);
			free_stack(stacks->b);
			free(stacks);
			free(line);
			free_gnl();
			print_message("Error\n");
		}
		free(line);
		line = get_next_line(0);
	}
	if ((is_sorted(stacks->a)) && is_empty(stacks->b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

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
	read_ops(stacks);
	free_stack(stacks->a);
	free_stack(stacks->b);
	free(stacks);
	close(0);
	// free_gnl();
}
