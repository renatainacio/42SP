/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 03:42:51 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/08 14:30:21 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	get_path(t_data *data, char **envp)
{
	char	*path_var;

	while (*envp)
	{
		if (ft_strncmp("PATH", *envp, 4) == 0)
			path_var = ft_strdup(*envp + 5);
		envp++;
	}
	if (path_var == NULL)
		exit_perror("PATH variable not found", 1, data);
	data->paths = ft_split(path_var, ':');
	free(path_var);
}

int	test_path(int i, int j, t_data *data)
{
	char	*temp;
	char	*path;

	temp = ft_strjoin(data->paths[j], "/");
	path = ft_strjoin(temp, data->args[i][0]);
	if (access(path, F_OK) == 0)
	{
		data->cmd_path[i] = ft_strdup(path);
		free(temp);
		free(path);
		return (1);
	}
	free(temp);
	free(path);
	return (0);
}

void	get_cmd_path(t_data *data, char **envp)
{
	int		i;
	int		j;

	get_path(data, envp);
	i = 0;
	while (i < data->cmd)
	{
		data->cmd_path[i] = NULL;
		j = 0;
		while (data->paths[j])
		{
			if (test_path(i, j, data) == 1)
				break ;
			j++;
		}
		if (data->cmd_path[i] == NULL)
		{
			ft_printf("bash: %s: command not found\n", data->args[i][0], 2);
			close(data->files_fd[0]);
			data->files_fd[0] = open("/dev/null", O_RDONLY);
		}
		i++;
	}
	free_matrix(data->paths);
}

int	check_quotation_marks(char *arg)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (arg[i])
	{
		if (arg[i] == '\"' || arg[i] == '\'')
			count++;
		i++;
	}
	if (count % 2 != 0)
		return (1);
	return (0);
}
