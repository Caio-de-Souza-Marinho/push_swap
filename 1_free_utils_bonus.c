/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_free_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:00:11 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/26 21:37:59 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// free a array of strings allocated with the ft_split function
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

void	cleanup(char *str, long *nbrs)
{
	if (str)
		free(str);
	if (nbrs)
		free(nbrs);
}

void	free_stacks(t_stack **stack_a, t_stack **stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
}
