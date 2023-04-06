/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   encode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:53:10 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/19 04:49:32 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	calculate_encoded_size(t_data *data)
{
	int	i;
	int	size;

	size = 0;
	for (i = 0; i < NCHAR; i++)
	{
		if (data->freq[i] != 0)
			size = size + (data->freq[i] * strlen(data->mapping[i]));
	}
	data->encoded_size = size;
}

void	encode(t_data *data, char *argv[])
{
	unsigned char	c;
	int				i;

	calculate_encoded_size(data);
	data->encoded_str = calloc(data->encoded_size + 1, sizeof(char));
	if (!data->encoded_str)
	{
		free_all(data, 3, 1);
	}
	for (i = 0; i < data->nfiles; i++)
	{
		close(data->fd[i]);
		data->fd[i] = open(argv[i + 1], O_RDONLY);
		while (read(data->fd[i], &c, 1))
			strcat(data->encoded_str, data->mapping[c]);
		close(data->fd[i]);
	}
}

int	zip(t_data *data)
{
	int				fd;
	int				i;
	int				count_bit;
	unsigned char	byte;
	unsigned char	aux;

	i = 0;
	byte = 0;
	count_bit = 7;
	fd = open("compact.qd", O_CREAT | O_WRONLY | O_TRUNC, 0777);
	if (fd == -1)45rt54
	{
		free_all(data, 0, 0);
		exit_message("Error creating the compact file.", -1);
	}
	while (data->encoded_str[i])
	{
		aux = 1;
		if (data->encoded_str[i] == '1')
		{
			aux = aux << count_bit;
			byte = byte | aux;
		}
		count_bit--;
		if (count_bit < 0)
		{
			write(fd, &byte, sizeof(unsigned char));
			byte = 0;
			count_bit = 7;
		}
		i++;
	}
	if (count_bit != 7)
		write(fd, &byte, sizeof(unsigned char));
	close(fd);
	return (0);
}
