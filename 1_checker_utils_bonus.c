/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_checker_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 22:18:57 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 22:35:36 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	free_and_print(char *msg, char *str)
{
	free(str);
	ft_printf(msg);
}

int	check_move(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "ss") == 0)
		return (1);
	else if (ft_strcmp(str, "pa") == 0)
		return (1);
	else if (ft_strcmp(str, "pb") == 0)
		return (1);
	else if (ft_strcmp(str, "ra") == 0)
		return (1);
	else if (ft_strcmp(str, "rb") == 0)
		return (1);
	else if (ft_strcmp(str, "rr") == 0)
		return (1);
	else if (ft_strcmp(str, "rra") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr") == 0)
		return (1);
	return (0);
}
