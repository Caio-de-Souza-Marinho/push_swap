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

int	find_biggest_value_in_stack(t_stack *stack)
{
	t_stack	*curr;
	int		biggest;

	if (!stack)
		return (0);
	curr = stack;
	biggest = curr->value;
	while (curr)
	{
		if (curr->value > biggest)
			biggest = curr->value;
		curr = curr->next;
	}
	return (biggest);
}

int	find_smallest_value_in_stack(t_stack *stack)
{
	t_stack	*curr;
	int		smallest;

	if (!stack)
		return (0);
	curr = stack;
	smallest = curr->value;
	while (curr)
	{
		if (curr->value < smallest)
			smallest = curr->value;
		curr = curr->next;
	}
	return (smallest);
}
