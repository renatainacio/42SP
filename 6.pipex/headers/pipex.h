/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:23:23 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/08 04:33:35 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include <errno.h>

typedef struct s_data
{
	char	***args;
	int		cmd;
	char	*input;
	char	*output;
	char	**paths;
	char	**cmd_path;
	int		files_fd[2];
	int		fd[2];
}	t_data;

void	ft_free(char ***array, int y);
int		handle_args(t_data *data, int argc, char **argv);
void	open_files(t_data *data);
void	mem_alloc(t_data *data, char **argv);
int		free_all(t_data *data);
void	free_matrix(char **array);
void	get_cmd_path(t_data *data, char **envp);
void	get_path(t_data *data, char **envp);
void	exit_perror(char *errmsg, int errnumber, t_data *data);
void	run_pipex(t_data *data, char **envp);
void	first_cmd(t_data *data, int *pipe, char **envp);
void	second_cmd(t_data *data, int *fd, char **envp);
int		check_quotation_marks(char *arg);
char	*switch_inside_quotation(char *str, char initial, char final);
void	switch_back(char **matrix);
void	close_and_free(t_data *data);

#endif