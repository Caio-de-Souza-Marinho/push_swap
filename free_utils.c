/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:07:23 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
