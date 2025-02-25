/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 22:08:08 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 21:28:42 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	current_index(t_stack *stack)
{
	int	i;
	int	median;

	i = 0;
	if (!stack)
		return ;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i <= median)
			stack->above_median = 1;
		else
			stack->above_median = 0;
		stack = stack->next;
		i++;
	}
}

t_stack	*get_cheapest_node(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	while (curr)
	{
		if (curr->cheapest)
			return (curr);
		curr = curr->next;
	}
	return (NULL);
}

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*cheapest_node;

	cheapest_node = get_cheapest_node(*stack_a);
	if (cheapest_node->above_median && cheapest_node->target->above_median)
		rotate_both(stack_a, stack_b, cheapest_node);
	else if (!(cheapest_node->above_median)
		&& !(cheapest_node->target->above_median))
		reverse_rotate_both(stack_a, stack_b, cheapest_node);
	prep_for_push(stack_a, cheapest_node, "a");
	prep_for_push(stack_b, cheapest_node->target, "b");
	push(stack_a, stack_b, 1, "pb");
}

void	move_b_to_a(t_stack **stack_a, t_stack **stack_b)
{
	prep_for_push(stack_a, (*stack_b)->target, "a");
	push(stack_b, stack_a, 1, "pa");
}

void	min_on_top(t_stack **a)
{
	while ((*a)->value != find_smallest_node_in_stack(*a)->value)
	{
		if (find_smallest_node_in_stack(*a)->above_median)
			rotate(a, 1, "ra");
		else
			reverse_rotate(a, 1, "rra");
	}
}
