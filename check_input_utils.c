/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 22:07:41 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/11 22:10:21 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// check for duplicate values and exits if found.
void	check_duplicate(long *nbrs)
{
	int	i;
	int	j;

	i = 0;
	while (nbrs[i])
	{
		j = i + 1;
		while (nbrs[j])
		{
			if (nbrs[i] == nbrs[j])
			{
				i = 0;
				ft_printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	// Allow leading + or -
	if (str[i] == '+' || str[i] == '-')
		i++;
	// If there are no digits after the sigh, it's invalid
	if (!str[i])
		return (0);
	// Check if the remainig characters are digits
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
