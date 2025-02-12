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

#include "libft/include/libft.h"
#include "stdbool.h"

typedef struct s_pslist
{
	int	value;
	struct s_pslist	*next;
	struct s_pslist	*prev;
}	t_pslist;

// input check
char	*init_str(int argc, char **argv);
long	*check_ints(char *str);
void	check_duplicate(long *nbrs);
int	is_valid_number(char *str);

// free
void	free_split(char **split);

#endif
