/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/18 19:23:57 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_nbrs(long *nbrs, int count);
int		check_args(int argc, char **argv, long **nbrs_ptr, int *num_count);
void	cleanup(char *str, long *nbrs);

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	long	*nbrs;
	int		num_count;

	stack_a = NULL;
	stack_b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	if (!check_args(argc, argv, &nbrs, &num_count))
		return (1);
	init_stack(&stack_a, nbrs, num_count);
	free(nbrs);
	print_stack(stack_a);
	free_stack(&stack_a);
	return (0);
}

int	check_args(int argc, char **argv, long **nbrs_ptr, int *num_count)
{
	char	*str;
	long	*nbrs;

	str = init_str(argc, argv);
	if (!str)
		return (0);
	nbrs = check_ints(str, num_count);
	if (!nbrs)
	{
		ft_printf("Error\n");
		return (0);
	}
	if (!check_duplicate(nbrs, *num_count) || !check_overflow(nbrs, *num_count))
	{
		cleanup(NULL, nbrs);
		return (0);
	}
	//print_nbrs(nbrs, *num_count);
	*nbrs_ptr = nbrs;
	//cleanup(str, nbrs);
	return (1);
}

void	cleanup(char *str, long *nbrs)
{
	if (str)
		free(str);
	if (nbrs)
		free(nbrs);
}

void	print_nbrs(long *nbrs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		ft_printf("numero %d - %d\n", i, nbrs[i]);
		i++;
	}
}
