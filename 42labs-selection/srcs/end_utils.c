/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:47:07 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 19:09:20 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	free_all(t_data *data, int breakpoint, int files)
{	
	int	i;

	i = 0;
	if (files == 1)
		close_files(data);
	free(data->fd);
	if (breakpoint == 1)
		return ;
	free_huffman_tree(data->list.start);	
	if (breakpoint == 2)
		return ;
	while (i < NCHAR)
		free(data->mapping[i++]);
	free(data->mapping);
	if (breakpoint == 3)
		return ;
	free(data->encoded_str);
}

void exit_message(char *msg, int exit_code)
{
	printf("%s\n", msg);
	exit(exit_code);
}

void	close_files(t_data *data)
{
	int	i;

	for (i = 0; i < data->nfiles; i++)
	{
		if (data->fd[i] > 0)
			close(data->fd[i]);
	}
	free(data->fd);
}

void	print_info(t_data *data)
{
	printf("Decompressed data: %s\n", data->decoded_str);
	printf("Original file size: %u\n", data->shared_data[0]);
	printf("Compressed file size: %u\n", data->shared_data[1]);
	printf("Compression ratio: %.2f\n",
		(float)data->shared_data[1] / data->shared_data[0]);
	printf("Time elapsed during decompression: %fs\n",
		(float)data->shared_data[2] / 1000000);
}

void	create_decompressed_file(t_data *data)
{
	unsigned int	i;
	int				fd_decompressed;

	fd_decompressed = open("decompressed", O_CREAT | O_RDWR | O_TRUNC, 0777);
	for (i = 0; i < data->shared_data[0]; i++)
		write(fd_decompressed, &data->decoded_str[i], 1);
}
