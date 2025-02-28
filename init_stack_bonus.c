/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:57:43 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *node);
void	free_stack(t_stack **stack);

// Initializes stack by converting an array of long integers into a
// doubly-linked list structure
// 1. Iterates through the input array
// 2. Creates a new node for each number
// 3. Adds each node to the end of the stack
// 4. Sets cleanup and memory allocation failure
void	init_stack(t_stack **stack, long *nbrs, int count)
{
	int		i;
	t_stack	*new_node;

	i = 0;
	while (i < count)
	{
		new_node = stack_new((int)nbrs[i]);
		if (!new_node)
		{
			free_stack(stack);
			return ;
		}
		stack_add_back(stack, new_node);
		i++;
	}
	current_index(new_node);
}

// Creates and initializes a new stack node
t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->push_cost = 0;
	new_node->above_median = 0;
	new_node->cheapest = 0;
	new_node->target = NULL;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

// Appends a node to the end of the stack
// 1. Handles empty stack case
// 2. Finds current last node
// 3. Links the new node to the end of the list
void	stack_add_back(t_stack **stack, t_stack *new_node)
{
	t_stack	*last;

	if (!stack)
		return ;
	if (!*stack)
	{
		*stack = new_node;
		return ;
	}
	last = find_last_node_in_stack(*stack);
	last->next = new_node;
	new_node->prev = last;
}

// Traverses the stack to find the last node
t_stack	*find_last_node_in_stack(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

// Safely deallocates all memory used by the stack
// 1. Traverses the stack while preserving next pointer
// 2. Frees each node sequentially
// 3. Sets the stack head to NULL to prevent dangling pointer (pointer that
// points to a memory location that has been freed)
void	free_stack(t_stack **stack)
{
	t_stack	*curr;
	t_stack	*next_node;

	if (!stack || !*stack)
		return ;
	curr = *stack;
	while (curr)
	{
		next_node = curr->next;
		free(curr);
		curr = next_node;
	}
	*stack = NULL;
}
