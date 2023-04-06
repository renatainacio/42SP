/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decode.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 01:55:04 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 19:15:17 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

unsigned int	check_value_bit(unsigned char byte, int i)
{
	unsigned char	aux;

	aux = 1 << i;
	return (aux & byte);
}

void	unzip(t_decoder *decoder)
{
	int				i;
	int				fd_compressed;
	unsigned char	byte;
	unsigned int	count;
	t_huffmanNode	*aux;

	count = 0;
	aux = decoder->list.start;
	fd_compressed = open("compact.qd", O_RDONLY);
	if (fd_compressed == -1)
	{
		printf("Error while opening files.\n");
		free_huffman_tree(decoder->list.start);
		return ;
	}
	while (read(fd_compressed, &byte, sizeof(unsigned char)))
	{
		decoder->shared_data[1]++;
		for (i = 7; i >= 0; i--)
		{
			if (check_value_bit(byte, i))
				aux = aux->right;
			else
				aux = aux->left;
			if (is_leaf(aux))
			{
				if (count < decoder->shared_data[0])
				{
					decoder->decoded_str[count] = aux->c;
					count++;
				}
				aux = decoder->list.start;
			}	
		}
	}
	decoder->decoded_str[count] = '\0';
	close(fd_compressed);
}

int	main(void)
{
	t_decoder	decoder;
	clock_t		t;
	double		time_elapsed_decoding;

	t = clock();
	decoder.freq = get_shared_memory(NCHAR, 0);
	decoder.shared_data = get_shared_memory(sizeof(unsigned int) * 3, 1);
	decoder.decoded_str = get_shared_memory_str(
			sizeof(unsigned char) * (decoder.shared_data[0] + 1), 2);
	if (!decoder.freq || !decoder.shared_data || !decoder.decoded_str)
	{
		printf("Error accessing shared memory block\n");
		exit(-1);
	}
	decoder.list.start = NULL;
	decoder.list.size = 0;
	if (create_list(&decoder.list, decoder.freq) == -1)
		return (-1);
	if (build_huffman_tree(&decoder.list) < 0)
	{
		free_huffman_tree(decoder.list.start);
		return (-1);
	}
	unzip(&decoder);
	t = clock() - t;
	time_elapsed_decoding = ((double) t) / CLOCKS_PER_SEC;
	decoder.shared_data[2] = time_elapsed_decoding * 1000000;
	free_huffman_tree(decoder.list.start);
	return (0);
}
