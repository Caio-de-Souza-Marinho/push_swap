/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:03:18 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/11 22:07:59 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft/include/libft.h"
# include <stdbool.h>
# include <limits.h>

typedef struct s_plist
{
	long			value;
	int				index;
	struct s_plist	*next;
	struct s_plist	*prev;
}	t_plist;

// input check
char	*init_str(int argc, char **argv);
long	*check_ints(char *str, int *count);
int		check_duplicate(long *nbrs, int count);
int		is_valid_number(char *str);
int		check_overflow(long *nbrs, int count);
int		check_args(int argc, char **argv);

// free
void	free_split(char **split);

// errors
void	errors(int exit_code);

#endif
