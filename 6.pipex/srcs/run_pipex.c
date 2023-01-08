/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run_pipex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 23:17:43 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/08 04:34:04 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	run_pipex(t_data *data, char **envp)
{
	int		pid1;
	int		pid2;
	int		fd[2];
	int		wstatus;

	if (pipe(fd) == -1)
		exit_perror("Error while generating the pipe.\n", 1, data);
	pid1 = fork();
	if (pid1 < 0)
		exit_perror("Error while forking.\n", 1, data);
	if (pid1 == 0)
		first_cmd(data, fd, envp);
	close(fd[1]);
	pid2 = fork();
	if (pid2 < 0)
		exit_perror("Error while forking.\n", 1, data);
	if (pid2 == 0)
		second_cmd(data, fd, envp);
	waitpid(pid2, &wstatus, 0);
	if (WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
		wstatus = WEXITSTATUS(wstatus);
	close(fd[0]);
	close_and_free(data);
	exit(wstatus);
}

void	first_cmd(t_data *data, int *fd, char **envp)
{
	dup2(data->files_fd[0], STDIN_FILENO);
	close(data->files_fd[0]);
	close(data->files_fd[1]);
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (data->cmd_path[0])
	{
		if (execve(data->cmd_path[0], data->args[0], envp) == -1)
			exit_perror("Failed executing first command", errno, data);
	}
	else
	{
		free_all(data);
		exit(127);
	}
}

void	second_cmd(t_data *data, int *fd, char **envp)
{
	close(data->files_fd[0]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(data->files_fd[1], STDOUT_FILENO);
	close(data->files_fd[1]);
	if (data->cmd_path[1])
	{
		if (execve(data->cmd_path[1], data->args[1], envp) == -1)
			exit_perror("Failed executing second command", errno, data);
	}
	else
	{
		free_all(data);
		exit(127);
	}
}
