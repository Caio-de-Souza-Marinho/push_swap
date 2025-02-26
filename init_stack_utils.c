/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 19:22:41 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_stack(t_stack *stack)
{
	t_stack	*curr;
	int		i;

	if (!stack)
		return ;
	i = 0;
	curr = stack;
	while (curr)
	{
		ft_printf("node %d value - %d\n", i, curr->value);
		i++;
		curr = curr->next;
	}
}

t_stack	*find_biggest_node_in_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	curr = stack;
	biggest = curr;
	while (curr)
	{
		if (curr->value > biggest->value)
			biggest = curr;
		curr = curr->next;
	}
	return (biggest);
}

t_stack	*find_smallest_node_in_stack(t_stack *stack)
{
	t_stack	*curr;
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	curr = stack;
	smallest = curr;
	while (curr)
	{
		if (curr->value < smallest->value)
			smallest = curr;
		curr = curr->next;
	}
	return (smallest);
}

int	stack_len(t_stack *stack)
{
	t_stack	*curr;
	int		len;

	if (!stack)
		return (0);
	curr = stack;
	len = 0;
	while (curr)
	{
		curr = curr->next;
		len++;
	}
	return (len);
}

int	greater(int num1, int num2)
{
	if (num1 > num2)
		return (num1);
	else
		return (num2);
}
