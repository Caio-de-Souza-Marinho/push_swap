/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_to_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 21:01:42 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 21:16:21 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_b(t_stack *stack_a, t_stack *stack_b);

// Prepares stack B nodes for movement calculations
// 1. Updates positional indexes in both stacks
// 2. Establishes target nodes in stack_a for each stack_b element
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_b);
	current_index(stack_a);
	set_target_b(stack_a, stack_b);
}

// Assigns target nodes in stack_a for each element in stack_b
// For each stack_b node:
// 1. Find the smallest value in stack_a that's larger then current stack_b
// 2. If no larger value found, target smallest stack_a element
void	set_target_b(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_a;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_b)
	{
		best_match_index = LONG_MAX;
		curr_a = stack_a;
		while (curr_a)
		{
			if (curr_a->value > stack_b->value
				&& curr_a->value < best_match_index)
			{
				best_match_index = curr_a->value;
				target_node = curr_a;
			}
			curr_a = curr_a->next;
		}
		if (best_match_index == LONG_MAX)
			stack_b->target = find_smallest_node_in_stack(stack_a);
		else
			stack_b->target = target_node;
		stack_b = stack_b->next;
	}
}
