/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:00:11 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// Safely deallocates memory for a 2D string array created by ft_split
// 1. Iterates through string array elements
// 2. Frees each individual string
// 3. Frees the array pointer itself
// Note: Designed specifically for ft_split allocations
void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

// Frees memory for input validation resources
void	cleanup(char *str, long *nbrs)
{
	if (str)
		free(str);
	if (nbrs)
		free(nbrs);
}

// Frees memory for both stacks in the program
void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	*stack_a = NULL;
	*stack_b = NULL;
}
