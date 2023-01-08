/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 16:45:16 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/05 13:41:31 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	handle_args(&data, argc, argv);
	open_files(&data);
	mem_alloc(&data, argv);
	get_cmd_path(&data, envp);
	run_pipex(&data, envp);
}
