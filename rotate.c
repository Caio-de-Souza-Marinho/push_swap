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

// Simultaneously rotates both stacks until target nodes reach top positions,
// optimizing move efficiency
// 1. Perform concurrent rotations while both stacks need adjustment
// 2. Update positional metadata after rotations complete
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node && (*b) != cheapest_node->target)
		rotate_ab(a, b, 1);
	current_index(*a);
	current_index(*b);
}

// Simultaneously reverse-rotates both stacks until target nodes reach 
// top positions, optimizing for bottom-half element movement
// 1. Perform concurrent reverse rotations until targets are positioned
// 2. Update positional metadata after rotations complete
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node)
{
	while ((*a) != cheapest_node && (*b) != cheapest_node->target)
		reverse_rotate_ab(a, b, 1);
	current_index(*a);
	current_index(*b);
}
