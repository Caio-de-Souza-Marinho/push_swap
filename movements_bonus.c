/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movements_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:35:36 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Swaps the first two elements of a stack
// 1. Validates that the stack has at least 2 elements
// 2. Swaps first and second node positions
// 3. Maintains doubly-linked list integrity
void	swap(t_stack **stack, int print, char *move)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
	if (ft_strncmp(move, "sa", 2) == 0 && print)
		ft_printf("sa\n");
	else if (ft_strncmp(move, "sb", 2) == 0 && print)
		ft_printf("sb\n");
}

// Shifts the stack upward - first element becomes the last
// 1. Validates stack has rotatable elements
// 2. Makes first node the new last node
// 3. Updates stack head to second node
void	rotate(t_stack **stack, int print, char *move)
{
	t_stack	*first;
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = find_last_node_in_stack(first);
	last->next = first;
	*stack = first->next;
	(*stack)->prev = NULL;
	first->prev = last;
	first->next = NULL;
	if (ft_strncmp(move, "ra", 2) == 0 && print)
		ft_printf("ra\n");
	else if (ft_strncmp(move, "rb", 2) == 0 && print)
		ft_printf("rb\n");
}

// Shifts the stack downward - last element becomes the first
// 1. Validates stack has rotatable elements
// 2. Makes last node the new first node
// 3. Updates stack head and links
void	reverse_rotate(t_stack **stack, int print, char *move)
{
	t_stack	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = find_last_node_in_stack(*stack);
	last->prev->next = NULL;
	last->next = *stack;
	last->prev = NULL;
	(*stack)->prev = last;
	*stack = last;
	if (ft_strncmp(move, "rra", 3) == 0 && print)
		ft_printf("rra\n");
	else if (ft_strncmp(move, "rrb", 3) == 0 && print)
		ft_printf("rrb\n");
}

// Moves top element from source stack to destination stack
// 1. Validates that the source stack has elements
// 2. Removes the top node from source
// 3. Adds the node to the top of destination
// 4. Maintains link integrity in both stacks
void	push(t_stack **src, t_stack **dest, int print, char *move)
{
	t_stack	*top_node;

	if (!(*src))
		return ;
	top_node = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	top_node->next = *dest;
	if (*dest)
		(*dest)->prev = top_node;
	*dest = top_node;
	top_node->prev = NULL;
	if (ft_strncmp(move, "pa", 2) == 0 && print)
		ft_printf("pa\n");
	else if (ft_strncmp(move, "pb", 2) == 0 && print)
		ft_printf("pb\n");
}
