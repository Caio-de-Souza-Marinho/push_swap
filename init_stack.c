/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 20:28:31 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*stack_new(int value);
void	stack_add_back(t_stack **stack, t_stack *node);
t_stack *stack_last(t_stack *stack);
void	free_stack(t_stack **stack);

// Append each input number as a node to stack a.
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
}

t_stack	*stack_new(int value)
{
	t_stack	*new_node;

	new_node = malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = 0;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

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
	last = stack_last(*stack);
	last->next = new_node;
	new_node->prev = last;
}

t_stack *stack_last(t_stack *stack)
{
	t_stack	*curr;

	if (!stack)
		return (NULL);
	curr = stack;
	while (curr->next)
		curr = curr->next;
	return (curr);
}

void	free_stack(t_stack **stack)
{
	t_stack *curr;
	t_stack *next_node;

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
