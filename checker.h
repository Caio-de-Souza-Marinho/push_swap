/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 19:44:06 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/26 22:19:29 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_stack
{
	int				value;
	int				index;
	int				push_cost;
	int				above_median;
	int				cheapest;
	struct s_stack	*target;
	struct s_stack	*next;
	struct s_stack	*prev;
}	t_stack;

// input check
char	*init_str(int argc, char **argv);
long	*check_ints(char *str, int *count);
int		check_duplicate(long *nbrs, int count);
int		is_valid_number(char *str);
int		check_overflow(long *nbrs, int count);

// free
void	free_split(char **split);
void	free_stack(t_stack **stack);
void	cleanup(char *str, long *nbrs);
void	free_stacks(t_stack **stack_a, t_stack **stack_b);

// init
void	init_stack(t_stack **stack, long *nbrs, int count);

// stack utils
t_stack	*find_biggest_node_in_stack(t_stack *stack);
t_stack	*find_smallest_node_in_stack(t_stack *stack);
t_stack	*find_last_node_in_stack(t_stack *stack);
int		stack_len(t_stack *stack);
int		greater(int num1, int num2);

// sort
int		is_sorted(t_stack *stack);

// sort utils
void	current_index(t_stack *stack);

// movements
void	swap(t_stack **stack, int print, char *move);
void	rotate(t_stack **stack, int print, char *move);
void	reverse_rotate(t_stack **stack, int print, char *move);
void	push(t_stack **src, t_stack **dest, int print, char *move);
void	swap_ab(t_stack **stack_a, t_stack **stack_b, int print);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int print);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int print);

// checker
void	process_input(t_stack **stack_a, t_stack **stack_b);

// chekcer utils
void	exit_ok(char *msg, char *str);
#endif
