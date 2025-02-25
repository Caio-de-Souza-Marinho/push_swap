/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:03:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/24 21:30:16 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>

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

// init
void	init_stack(t_stack **stack, long *nbrs, int count);

// debug
void	print_stack(t_stack *stack);

// stack utils
t_stack	*find_biggest_node_in_stack(t_stack *stack);
t_stack	*find_smallest_node_in_stack(t_stack *stack);
t_stack	*find_last_node_in_stack(t_stack *stack);
int		stack_len(t_stack *stack);

// sort
int		is_sorted(t_stack *stack);
void	sort_stack(t_stack **stack_a);
void	three_sort(t_stack **stack);
void	turk(t_stack **stack_a, t_stack **stack_b);
void	init_nodes_a(t_stack *stack_a, t_stack *stack_b);
void	init_nodes_b(t_stack *stack_a, t_stack *stack_b);

// sort utils
void	current_index(t_stack *stack);
t_stack	*get_cheapest_node(t_stack *stack);
void	rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	reverse_rotate_both(t_stack **a, t_stack **b, t_stack *cheapest_node);
void	prep_for_push(t_stack **stack, t_stack *top_node, char *stack_name);
void	move_a_to_b(t_stack **stack_a, t_stack **stack_b);
void	move_b_to_a(t_stack **stack_a, t_stack **stack_b);
void	min_on_top(t_stack **a);

// movements
void	swap(t_stack **stack, int print, char *move);
void	rotate(t_stack **stack, int print, char *move);
void	reverse_rotate(t_stack **stack, int print, char *move);
void	push(t_stack **src, t_stack **dest, int print, char *move);
void	swap_ab(t_stack **stack_a, t_stack **stack_b, int print);
void	rotate_ab(t_stack **stack_a, t_stack **stack_b, int print);
void	reverse_rotate_ab(t_stack **stack_a, t_stack **stack_b, int print);

#endif
