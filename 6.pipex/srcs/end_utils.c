/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 04:03:36 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/08 04:40:55 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_free(char ***array, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < y)
	{
		j = 0;
		while (array[i][j])
		{
			free(array[i][j]);
			j++;
		}
		free(array[i]);
		i++;
	}
	free(array);
}

void	free_matrix(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	free_all(t_data *data)
{
	int	i;

	i = 0;
	ft_free(data->args, data->cmd);
	while (i < data->cmd)
	{
		free(data->cmd_path[i]);
		i++;
	}
	free(data->cmd_path);
	return (0);
}

void	exit_perror(char *errmsg, int errnumber, t_data *data)
{
	close(data->files_fd[0]);
	close(data->files_fd[1]);
	free_all(data);
	perror(errmsg);
	exit(errnumber);
}

void	close_and_free(t_data *data)
{
	close(data->files_fd[0]);
	close(data->files_fd[1]);
	free_all(data);
}
