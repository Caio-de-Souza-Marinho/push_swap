/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_check_input_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:03:34 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/26 21:37:59 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

// check for duplicate values and exits if found.
int	check_duplicate(long *nbrs, int count)
{
	int	i;
	int	j;

	i = 0;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nbrs[i] == nbrs[j])
			{
				ft_printf("Error\n");
				return (0);
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_overflow(long *nbrs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (nbrs[i] > INT_MAX || nbrs[i] < INT_MIN)
		{
			ft_printf("Error\n");
			return (0);
		}
		i++;
	}
	return (1);
}

// Allow leading + or -
// If there are no digits after the sign, it's invalid
// Check if the remainig characters are digits
int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}
