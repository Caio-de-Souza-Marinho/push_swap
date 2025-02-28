/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_to_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 21:05:19 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 21:20:55 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_target_a(t_stack *stack_a, t_stack *stack_b);
void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b);
void	set_cheapest(t_stack *stack);

// Prepares stack A nodes for sorting calculations
// 1. Refresh positional indexes in both stacks
// 2. Find optimal targets in stack_b for stack_a nodes
// 3. Calculate movement costs for each node
// 4. Mark node with lowest cost as cheapest
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

// Assigns target nodes in stack_b for each stack_a element
// For each stack_a node:
// 1. Find the largest value in stack_b that's smaller than current stack_a
// 2. If no smaller value found, target the largest stack_b element
void	set_target_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr_b;
	t_stack	*target_node;
	long	best_match_index;

	while (stack_a)
	{
		best_match_index = LONG_MIN;
		curr_b = stack_b;
		while (curr_b)
		{
			if (curr_b->value < stack_a->value
				&& curr_b->value > best_match_index)
			{
				best_match_index = curr_b->value;
				target_node = curr_b;
			}
			curr_b = curr_b->next;
		}
		if (best_match_index == LONG_MIN)
			stack_a->target = find_biggest_node_in_stack(stack_b);
		else
			stack_a->target = target_node;
		stack_a = stack_a->next;
	}
}

// Calculates movement costs for transferring nodes from A to B
// Cost calculation cases:
// 1. Both nodes in the top half: cost = max(indexes)
// 2. Both nodes in bottom half: cost = max(reverse indexes)
// 3. Mixed positions: sum of individual costs
void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	t_stack	*curr;	

	curr = stack_a;
	while (curr)
	{
		if (curr->index <= ((stack_len(stack_a) - 1) / 2)
			&& curr->target->index <= ((stack_len(stack_b) - 1) / 2))
			curr->push_cost = greater(curr->index, curr->target->index);
		else if (curr->index > (stack_len(stack_a) - 1) / 2
			&& curr->target->index > (stack_len(stack_a) - 1) / 2)
			curr->push_cost = greater((stack_len(stack_a) - curr->index),
					stack_len(stack_b) - curr->target->index);
		else if (curr->index <= (stack_len(stack_a) - 1) / 2
			&& curr->target->index > (stack_len(stack_b) - 1) / 2)
			curr->push_cost = curr->index + stack_len(stack_b)
				- curr->target->index;
		else
			curr->push_cost = stack_len(stack_a)
				- curr->index + curr->target->index;
		curr = curr->next;
	}
}

// Marks node with lowest push cost as cheapest move
// 1. Iterates through all nodes
// 2. Tracks lowest cost encountered
// 3. Flags cheapest node for priority movement
void	set_cheapest(t_stack *stack)
{
	long	cheapest_value;
	t_stack	*cheapest_node;

	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = 1;
}
