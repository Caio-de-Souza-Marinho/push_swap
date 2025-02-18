/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:03:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/17 20:29:10 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_stack
{
	long			value;
	int				index;
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

// errors
void	errors(int exit_code);

// init
void	init_stack(t_stack **stack, long *nbrs, int count);

#endif
