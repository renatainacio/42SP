/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 03:16:04 by rinacio           #+#    #+#             */
/*   Updated: 2023/02/28 15:35:24 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	init(t_data *data)
{
	data->args = malloc(sizeof(int) * data->nargs);
	if (!data->args)
		return (1);
	return (0);
}

int	check_args(char *argv[], t_data *data)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isdigit(argv[i][j]) &&
			!(j == 0 && (argv[i][j] == '+' || argv[i][j] == '-')))
				return (ft_error(1, 2, data));
			j++;
		}
		if (check_duplicates(data->args, i, ft_atoi(argv[i])))
			return (ft_error(1, 3, data));
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < INT_MIN)
			return (ft_error(1, 4, data));
		data->args[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	if (data->nargs < 2)
		return (ft_error(0, 1, data));
	return (0);
}

int	check_duplicates(int *arr, int i, int n)
{
	int	k;

	k = 0;
	while (k < i - 1)
	{
		if (n == arr[k])
			return (1);
		k++;
	}
	return (0);
}

int	is_sorted(t_data *data, int free_if_sorted)
{
	int	i;

	i = 1;
	while (i < data->nargs)
	{
		if (data->args[i] < data->args[i - 1])
			return (0);
		i++;
	}
	if (free_if_sorted)
		free(data->args);
	return (1);
}

int	ft_error(int printerror, int e, t_data *data)
{
	if (printerror)
		write(2, "Error\n", 6);
	free(data->args);
	return (e);
}
