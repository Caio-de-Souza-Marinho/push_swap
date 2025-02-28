/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 15:47:19 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 21:39:10 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
int		is_sorted(t_stack *stack);

// Main sorting controller that selects best algorithm based on stack size
// 1. Checks if stack is already sorted
// 2. Handles 2-element stack with a single swap
// 3. Handels 3-element stack with dedicated sort
// 4. Uses Turk algorithm for larger stacks
void	sort_stack(t_stack **stack_a)
{
	t_stack	*stack_b;

	stack_b = NULL;
	if (!is_sorted(*stack_a))
	{
		if (stack_len(*stack_a) == 2)
			swap(stack_a, 1, "sa");
		else if (stack_len(*stack_a) == 3)
			three_sort(stack_a);
		else
			turk(stack_a, &stack_b);
	}
}

// Checks if stack is sorted in ascending order
int	is_sorted(t_stack *stack)
{
	t_stack	*curr;

	curr = stack;
	while (curr->next)
	{
		if (curr->value > curr->next->value)
			return (0);
		curr = curr->next;
	}
	return (1);
}

// Specialized sorting algorithm for 3-element stacks
// 1. Identify largest element
// 2. Position largest element at the bottom of the stack
// 3. Final swap if needed
void	three_sort(t_stack **stack)
{
	t_stack	*biggest;

	biggest = find_biggest_node_in_stack(*stack);
	if (*stack == biggest)
		rotate(stack, 1, "ra");
	else if ((*stack)->next == biggest)
		reverse_rotate(stack, 1, "rra");
	if ((*stack)->value > (*stack)->next->value)
		swap(stack, 1, "sa");
}

// Turk algorithm
// 1. Push elements to stack_b until 3 remain in stack_a
// 2. Sort remaining 3 elements in stack_a
// 3. Return elements from stack_b while maintaining order
// 4. Final position adjustment
void	turk(t_stack **stack_a, t_stack **stack_b)
{
	int	len_a;

	len_a = stack_len(*stack_a);
	if (len_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 1, "pb");
	if (len_a-- > 3 && !is_sorted(*stack_a))
		push(stack_a, stack_b, 1, "pb");
	while (len_a-- > 3 && !is_sorted(*stack_a))
	{
		init_nodes_a(*stack_a, *stack_b);
		move_a_to_b(stack_a, stack_b);
	}
	three_sort(stack_a);
	while (*stack_b)
	{
		init_nodes_b(*stack_a, *stack_b);
		move_b_to_a(stack_a, stack_b);
	}
	current_index(*stack_a);
	min_on_top(stack_a);
}

// Optimally rotates the stack to position target node at the top
// Uses either rotate or reverse rotate based on shortest path
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	int	forward_moves;
	int	reverse_moves;

	forward_moves = top_node->index;
	reverse_moves = stack_len(*stack) - top_node->index;
	if (forward_moves <= reverse_moves)
	{
		while (*stack != top_node)
		{
			if (stack_name == 'a')
				rotate(stack, 1, "ra");
			else
				rotate(stack, 1, "rb");
		}
	}
	else
	{
		while (*stack != top_node)
		{
			if (stack_name == 'a')
				reverse_rotate(stack, 1, "rra");
			else
				reverse_rotate(stack, 1, "rrb");
		}
	}
}
