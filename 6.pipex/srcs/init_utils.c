/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:12:17 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/08 04:17:13 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	handle_args(t_data *data, int argc, char **argv)
{
	if (argc != 5)
	{
		ft_printf("Invalid number of arguments. There should be exactly 4.\n",
			argc, argv[0]);
		exit (1);
	}
	data->input = argv[1];
	data->cmd = argc - 3;
	data->output = argv[argc - 1];
	return (0);
}

void	open_files(t_data *data)
{
	data->files_fd[1] = open(data->output, O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (data->files_fd[1] == -1)
	{	
		ft_putstr_fd("bash: ", 2);
		perror(data->output);
		perror("Error while creating outfile!\n");
		exit (1);
	}
	data->files_fd[0] = open(data->input, O_RDONLY);
	if (data->files_fd[0] == -1)
	{
		if (access(data->input, F_OK) == 0)
		{
			perror("Infile can't be read!\n");
			exit (0);
		}
		else
		{
			ft_putstr_fd("bash: ", 2);
			perror(data->input);
			data->files_fd[0] = open("/dev/null", O_RDONLY);
		}
	}
}

void	mem_alloc(t_data *data, char **argv)
{
	int	i;

	data->args = (char ***)malloc(sizeof(char **) * data->cmd);
	data->cmd_path = (char **)malloc(sizeof(char *) * data->cmd);
	if (!data->args || !data->cmd_path)
		exit_perror("Memory allocation error", 1, data);
	i = 0;
	while (i < data->cmd)
	{
		if (check_quotation_marks(argv[i + 2]) != 0)
			exit_perror("Unpaired quotes", 1, data);
		argv[i + 2] = switch_inside_quotation(argv[i + 2], ' ', 1);
		data->args[i] = ft_split(argv[i + 2], ' ');
		switch_back(data->args[i]);
		if (!data->args[i])
			exit_perror("Memory allocation error", 1, data);
		i++;
	}	
}

char	*switch_inside_quotation(char *str, char initial, char final)
{
	int		i;
	char	quote;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
		{
			quote = str[i];
			i++;
			while (str[i] != quote)
			{
				if (str[i] == initial)
					str[i] = final;
				i++;
			}
		}
		i++;
	}
	return (str);
}

void	switch_back(char **matrix)
{
	int		i;
	char	*temp;

	i = 0;
	while (matrix[i])
	{
		matrix[i] = switch_inside_quotation(matrix[i], 1, ' ');
		temp = ft_strtrim(matrix[i], "\'\"");
		free(matrix[i]);
		matrix[i] = ft_strdup(temp);
		free(temp);
		i++;
	}
}
