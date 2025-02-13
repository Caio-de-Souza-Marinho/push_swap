/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 21:17:00 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/11 22:27:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	check_char(char *arg, char **splited);
static long	*init_nbrs(char **splited, int size);

// transform the arguments in a string separated by a space
char	*init_str(int argc, char **argv)
{
	char	*str;
	char	*tmp_ptr;
	int		i;

	i = 1;
	str = ft_strdup("");
	if (!str)
		return (NULL);
	while (i < argc)
	{
		tmp_ptr = str;
		str = ft_strjoin(str, " ");
		if (!str)
			return (NULL);
		free(tmp_ptr);
		tmp_ptr = str;
		str = ft_strjoin(str, argv[i]);
		if (!str)
			return (NULL);
		free(tmp_ptr);
		i++;
	}
	return (str);
}

// split a string in other strings and checks if there's anything other than
// a number or a sign and number
long	*check_ints(char *str, int *count)
{
	char	**splited;
	long	*pts;
	int		i;
	int		j;

	i = 0;
	splited = ft_split(str, ' ');
	free(str);
	if (!splited)
		return (NULL);
	while (splited[i])
	{
		j = 0;
		while (splited[i][j])
		{
			check_char(&splited[i][j], splited);
			j++;
		}
		i++;
	}
	*count = i;
	pts = init_nbrs(splited, i);
	free_split(splited);
	return (pts);
}

// checks if there is anything other than a number or a sign and number
static void	check_char(char *arg, char **splited)
{
	int		trigger;

	trigger = 0;
	// Check if the character is not a digit, +, -, or space
	if (!ft_isdigit(*arg) && *arg != '-' && *arg != '+')
		trigger = 1;
	// Check for multiple signs or signs without digits
	if ((*arg == '-' || *arg == '+') && !ft_isdigit(*(arg + 1)))
		trigger = 1;
	// If an error is detected, clean and exit
	if (trigger == 1)
	{
		free_split(splited);
		ft_printf("Error\n");
		exit(1);
	}
}

static long	*init_nbrs(char **splited, int size)
{
	long	*pts;
	long	i;

	i = 0;
	pts = (long *)malloc(size * sizeof(long));
	if (!pts)
		return (NULL);
	while (i < size)
	{
		if (!is_valid_number(splited[i]))
		{
			free(pts);
			return (NULL);
		}
		pts[i] = ft_atol(splited[i]);
		i++;
	}
	return (pts);
}
