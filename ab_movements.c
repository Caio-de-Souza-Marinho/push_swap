/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ab_movements.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:21:30 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 20:07:34 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	swap(stack_a, 0, "");
	swap(stack_b, 0, "");
	if (print)	
		ft_printf("ss\n");
}

void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	rotate(stack_a, 0, "");
	rotate(stack_b, 0, "");
	if (print)
		ft_printf("rr\n");
}

void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int print)
{
	reverse_rotate(stack_a, 0, "");
	reverse_rotate(stack_b, 0, "");
	if (print)
		ft_printf("rrr\n");
}
