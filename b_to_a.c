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

void	init_nodes_b(t_stack *stack_a, t_stack *stack_b)
{
	current_index(stack_b);
	set_target_b(stack_a, stack_b);
}

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
