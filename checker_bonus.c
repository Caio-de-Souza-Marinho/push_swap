/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 21:24:59 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

void	process_move(char *str, t_stack **stack_a, t_stack **stack_b);
int		check_move(char *str);
void	apply_move(char *str, t_stack **stack_a, t_stack **stack_b);

// Main loop for processing moves from standard input
// 1. Continuously reads input until EOF
// 2. Validates and applies each move
// 3. Checks final stack state after EOF
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
				free_and_print("OK\n", str);
				exit (EXIT_SUCCESS);
			}
			break ;
		}
		if (ft_strlen(str) > 0)
			process_move(str, stack_a, stack_b);
		free(str);
	}
}

// Handles individual move validation and excecution
// 1. Sanitizes input by removing newline
// 2. Validates move syntax
// 3. Applies move if valid
// 4. Handles early success condition
void	process_move(char *str, t_stack **stack_a, t_stack **stack_b)
{
	size_t	len;

	len = ft_strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = '\0';
	if (check_move(str))
	{
		if (is_sorted(*stack_a) == 1 && stack_len(*stack_b) == 0)
		{
			free_and_print("OK\n", str);
			exit (EXIT_SUCCESS);
		}
		apply_move(str, stack_a, stack_b);
	}
	else
	{
		free_and_print("Error\n", str);
		exit (EXIT_SUCCESS);
	}
}

// Dispatches move operations to appropriate stack functions
void	apply_move(char *str, t_stack **stack_a, t_stack **stack_b)
{
	if (ft_strcmp(str, "sa") == 0)
		swap(stack_a, 0, "sa");
	else if (ft_strcmp(str, "sb") == 0)
		swap(stack_b, 0, "sb");
	else if (ft_strcmp(str, "ss") == 0)
		swap_ab(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "pa") == 0)
		push(stack_b, stack_a, 0, "pa");
	else if (ft_strcmp(str, "pb") == 0)
		push(stack_a, stack_b, 0, "pb");
	else if (ft_strcmp(str, "ra") == 0)
		rotate(stack_a, 0, "ra");
	else if (ft_strcmp(str, "rb") == 0)
		rotate(stack_b, 0, "rb");
	else if (ft_strcmp(str, "rr") == 0)
		rotate_ab(stack_a, stack_b, 0);
	else if (ft_strcmp(str, "rra") == 0)
		reverse_rotate(stack_a, 0, "rra");
	else if (ft_strcmp(str, "rrb") == 0)
		reverse_rotate(stack_b, 0, "rrb");
	else if (ft_strcmp(str, "rrr") == 0)
		reverse_rotate_ab(stack_a, stack_b, 0);
}
