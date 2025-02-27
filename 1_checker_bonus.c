/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_checker_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:24:59 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/26 22:48:07 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

//void	process_move(char *str, t_stack **stack_a, t_stack **stack_b);

void	process_input(t_stack **stack_a, t_stack **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(STDIN_FILENO);
		if (!str)
		{
			if (is_sorted(*stack_a) == 1 && stack_len(*stack_b) == 0)
			{
				exit_ok("OK\n", str);
				//free_stack(stack_a);
				exit (EXIT_SUCCESS);
			}
			//free_stacks(stack_a, stack_b);
			break ;
		}
		/*
		if (ft_strlen(str) > 0)
			process_move(str, stack_a, stack_b);
		*/
		free(str);
	}
}

/*
void	process_move(char *str, t_stack **stack_a, t_stack **stack_b)
{

}
*/
