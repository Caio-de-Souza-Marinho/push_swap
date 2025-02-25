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

void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name);
int	is_sorted(t_stack *stack);

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

void	prep_for_push(t_stack **stack, t_stack *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				rotate(stack, 1, "ra");
			else
				reverse_rotate(stack, 1, "rra");
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rotate(stack, 1, "rb");
			else
				reverse_rotate(stack, 1, "rrb");
		}
	}
}
