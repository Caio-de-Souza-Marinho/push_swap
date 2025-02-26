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

void	init_nodes_a(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_a);
	current_index(stack_b);
	set_target_a(stack_a, stack_b);
	cost_analysis_a(stack_a, stack_b);
	set_cheapest(stack_a);
}

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

/*
void	cost_analysis_a(t_stack *stack_a, t_stack *stack_b)
{
	int	len_a;
	int	len_b;
	int	cost_a;
	int	cost_b;

	len_a = stack_len(stack_a);
	len_b = stack_len(stack_b);
	while (stack_a)
	{
		cost_a = stack_a->index;
		if (!stack_a->above_median)
			cost_a = len_a - stack_a->index;
		cost_b = stack_a->target->index;
		if (!stack_a->target->above_median)
			cost_b = len_b - stack_a->target->index;
		stack_a->push_cost = cost_a + cost_b;
		stack_a = stack_a->next;
	}
}
*/

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
