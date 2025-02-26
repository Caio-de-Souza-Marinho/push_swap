/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 20:02:07 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 20:22:49 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node && (*b) != cheapest_node->target)
		rotate_ab(a, b, 1);
	current_index(*a);
	current_index(*b);
}

void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node && (*b) != cheapest_node->target)
		reverse_rotate_ab(a, b, 1);
	current_index(*a);
	current_index(*b);
}
