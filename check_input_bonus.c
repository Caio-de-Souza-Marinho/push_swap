/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: caide-so <caide-so@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 20:03:20 by caide-so          #+#    #+#             */
/*   Updated: 2025/02/27 23:00:30 by caide-so         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

static long	*init_nbrs(char **splited, int size);

// Concatenates command-line arguments into a single space-separeted-string
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

// Splits a space-separeted string into individual numbers and validates them
long	*check_ints(char *str, int *count)
{
	char	**splited;
	long	*pts;
	int		i;

	i = 0;
	splited = ft_split(str, ' ');
	free(str);
	if (!splited)
		return (NULL);
	while (splited[i])
		i++;
	*count = i;
	pts = init_nbrs(splited, i);
	free_split(splited);
	return (pts);
}

// Converts an array of strings into an array of long integers
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
