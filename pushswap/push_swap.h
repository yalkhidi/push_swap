/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yalkhidi <yalkhidi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/21 14:28:56 by yalkhidi          #+#    #+#             */
/*   Updated: 2025/05/12 11:43:29 by yalkhidi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdbool.h>
# include <stdlib.h>
# include <unistd.h>
#include "get_next_line/get_next_line.h"

typedef struct s_node
{
	long			value;
	struct s_node	*next;
}					t_node;
typedef struct s_stack
{
	t_node			*top;
	int				size;
}					t_stack;

typedef struct t_stacks
{
	t_stack			*a;
	t_stack			*b;
}					t_stacks;

typedef struct s_data
{
	int				b_min;
	int				b_max;
	int				a_index;
	int				b_index;
	int				total;
}					t_data;
//	Parsing
bool		check_valid_chars(char **str);
bool		is_valid_token(char *str);
bool		check_valid_operators(int ac, char **av);
bool		check_dup(t_stack *stack);
t_stack		*build_stack(int ac, char **av);
t_stacks	*parse_a(int ac, char **av, t_stacks *stacks);
//	Operations
void		pa(t_stacks *stacks, bool print);
void		pb(t_stacks *stacks, bool print);
void		rra(t_stack *a, bool print);
void		rrb(t_stack *b, bool print);
void		rrr(t_stacks *stacks, bool print);
void		ra(t_stack *a, bool print);
void		rb(t_stack *b, bool print);
void		rr(t_stacks *stacks, bool print);
void		sa(t_stack *a, bool print);
void		sb(t_stack *b, bool print);
void		ss(t_stacks *stacks, bool print);
t_stack		*create_stack(void);
bool		is_empty(t_stack *stack);
void		push(t_stack *stack, long value);
void		pop(t_stack *stack);
long		peek(t_stack *stack);

//	Utilities
long		ft_atoi(char *str);
bool		ft_isdigit(char d);
bool		is_within_limits(long num);
void		print_message(char *message);
void		free_stack(t_stack *stack);
char		**ft_split(char const *s);
void		free_split(char **split);

//	Algorithm
int			get_rotation_cost(int size, int index);
int			get_total_cost(t_stacks *stacks, int a_index, int value,
				t_data *data);
void		update_data(t_data *data, int total, int a_index, int b_index);
void		calculate(t_stacks *stacks, t_data *data);
void		rotate_to_index(t_stack *stack, int index, char name);
void		execute_rr(t_stacks *stacks, int a_rot, int b_rot);
void		execute_rrr(t_stacks *stacks, int a_rot, int b_rot);
void		execute_moves(t_stacks *stacks, t_data data);
int			get_index(t_stack *stack, int value);
int			find_insertion_b(t_stack *b, int value, t_data *data);
int			get_max(t_stack *stack);
int			get_min(t_stack *stack);
void		set_min_max(t_stack *b, t_data *data);
bool		is_sorted(t_stack *stack);
void		sort_three(t_stack *stack);
int			find_insertion_a(t_stack *a, int value);
void		push_back_to_a(t_stacks *stacks);
void		mechanical_turk(t_stacks *stacks);

//Bonus
void	free_gnl(void);
int	ft_strncmp(const char *s1, const char *s2, size_t n);
int	ft_strcmp(char *s1, char *s2);
int	ops_cmp(char *line, t_stacks *stacks);
int	ops_cmp2(char *line, t_stacks *stacks);
int	check_operations(char *line, t_stacks *stacks);
void	read_ops(t_stacks *stacks);

#endif