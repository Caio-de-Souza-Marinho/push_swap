/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/11 22:17:14 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_argv(char **argv);
void	errors(int exit_code);
void	print_nbrs(long *nbrs);

int	main(int argc, char **argv)
{
	char	*str;
	t_pslist	*stack_a;
	long	*nbrs;

	stack_a = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	str = init_str(argc, argv);
	if (str == NULL)
		return (1);
	nbrs = check_ints(str);
	check_duplicate(nbrs);
	print_nbrs(nbrs);
	//get_arguments(argc, argv);
	//init_stack(&a, argv + 1, argc == 2);
	return (0);
}

void	print_nbrs(long *nbrs)
{
	int	i;

	i = 0;
	while (nbrs[i])
	{
		ft_printf("numero %d - %d\n", i, nbrs[i]);
		i++;
	}
}

void	errors(int exit_code)
{
	ft_printf("Error\n");
	exit(exit_code);
}
