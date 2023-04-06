/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_decoder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 13:22:11 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 13:35:39 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	execute_decoder(char *envp[])
{
	int		pid;
	int		wstatus;
	char	**arg;

	arg = NULL;
	pid = fork();
	if (pid < 0)
	{
		printf("Error while forking.\n");
		return (-1);
	}
	if (pid == 0)
	{
		if (execve("decoder", arg, envp) == -1)
			exit(-1);
	}
	wait(&wstatus);
	if (!WIFEXITED(wstatus) && WEXITSTATUS(wstatus) != 0)
		printf("Error executing the decoder\n");
	return (wstatus);
}
