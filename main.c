/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 22:02:55 by caide-so          #+#    #+#             */
/*   Updated: 2025/01/29 22:03:08 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_args(char **argv);
void	print_argv(char **argv);
void	errors(int exit_code);
void	init_stack(t_pslist **a, char **argv, bool argc_is_2);
void	append_node(t_pslist **lst, int num);

int	main(int argc, char **argv)
{
	t_pslist	*a;
	t_pslist	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1][0]))
		return (1);
	else if (argc == 2)
		argv = ft_split(argv[1], ' ');
	print_argv(argv);
	//init_stack(&a, argv + 1, argc == 2);
	return (0);
}

void	init_stack(t_pslist **a, char **argv, bool argc_is_2)
{
	int	i;
	long	nbr;

	i = 0;
	while (argv[i])
	{
		//if (error_syntax(argv[i])
      			//error_free(a, argv, argc_is_2);
		//nbr = ft_atol(argv[i]);
		// verify int max int min
			//error_free(a, argv, argc_is_2);
		// verify duplicates
			//error_free(a, argv, argc_is_2);
		//append_node(a, (int)nbr);
		i++;
	}
}

/*
void	append_node(t_pslist **lst, int num)
{

}
*/

// degub functions
void	print_argv(char **argv)
{
	int	i;

	i = 0;
	ft_printf("==========PRINT ARGV============\n");
	while (argv[i])
	{
		ft_printf("argv %d - %s\n", i, argv[i]);
		i++;
	}
}

/*
int	check_args(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!ft_isdigit(argv[i][0]))
			return (0);
		i++;
	}
	return (1);
}
*/

void	errors(int exit_code)
{
	ft_printf("Error\n");
	exit(exit_code);
}
