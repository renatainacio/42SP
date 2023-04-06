/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:47:07 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 18:30:41 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	args_check(int argc, t_data *data)
{
	data->nfiles = argc - 1;
	if (argc < 2)
		exit_message("Please inform at least one file to be compressed.", -1);
}

int	open_files(char *argv[], t_data *data)
{	
	int	i;

	data->fd = (int *)malloc(sizeof(int) * (data->nfiles));
	for (i = 0; i < data->nfiles; i++)
	{
		data->fd[i] = open(argv[i + 1], O_RDONLY);
		if (data->fd[i] == -1)
		{
			if (access(argv[1], F_OK) == 0)
				printf("Informed file can't be read.\n");
			else
				printf("Informed file not found.\n");
			close_files(data);
			exit (-1);
		}
	}
	return (0);
}

void	init_variables(t_data *data)
{
	int		i;

	data->freq = get_shared_memory(NCHAR, 0);
	data->shared_data = get_shared_memory(sizeof(unsigned int) * 3, 1);
	if (!data->freq || !data->shared_data)
	{
		free_all(data, 1, 1);
		exit_message("Error in shared memory block", -1);
	}
	for (i = 0; i < NCHAR; i++)
	{
		data->ascii[i] = i;
		data->freq[i] = 0;
	}
	data->list.start = NULL;
	data->list.size = 0;
	data->shared_data[0] = 0;
	data->shared_data[1] = 0;
	data->shared_data[2] = 0;
}

int	clean_shm(char *envp[])
{
	int		pid;
	int		wstatus;
	char	*arg[3];

	arg[0] = "ipcrm";
	arg[1] = "a";
	arg[2] = NULL;
	pid = fork();
	if (pid < 0)
		return (-1);
	if (pid == 0)
	{
		if (execve("./usr/bin/ipcrm", arg, envp) == -1)
			exit(-1);
	}
	wait(&wstatus);
	if (!WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
		printf("Error executing ipcrm\n");
	return (wstatus);
}
