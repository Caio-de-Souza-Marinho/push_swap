/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_movements_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:34:40 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Perform simultaneous swap operations on both stacks
// 1. Executes swap on both stacks without individual operations printing
// 2. Prints combined "ss" operation if requested
void	swap_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a, 0, "");
	swap(stack_b, 0, "");
	if (print)
		ft_printf("ss\n");
}

// Executes concurrent rotate operations on both stacks
// Note: More efficient than separate rotations when both stacks need shifting
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a, 0, "");
	rotate(stack_b, 0, "");
	if (print)
		ft_printf("rr\n");
}

// Performs simultaneous reverse rotations on both stacks
// Note: Reduces output commands when both stacks need bottom-to-top rotations
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a, 0, "");
	reverse_rotate(stack_b, 0, "");
	if (print)
		ft_printf("rrr\n");
}
