/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 03:20:07 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 18:55:51 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	main(int argc, char *argv[], char *envp[])
{
	t_data	data;

	args_check(argc, &data);
	clean_shm(envp);
	open_files(argv, &data);
	init_variables(&data);
	get_frequency(&data);
	if (create_list(&data.list, data.freq) == -1)
	{
		free_all(&data, 1, 1);
		exit_message("Memory allocation error while creating list.\n", -1);
	}
	data.tree_height = build_huffman_tree(&data.list);
	if (data.tree_height < 0)
	{
		free_all(&data, 2, 1);
		exit_message("Memory allocation error in build Huffman tree.", -1);
	}
	alloc_mapping(data.tree_height, &data);
	generate_mapping(&data, data.list.start, "");
	encode(&data, argv);
	zip(&data);
	data.decoded_str = get_shared_memory_str(
			sizeof(unsigned char) * (data.shared_data[0] + 1), 2);
	if (!data.decoded_str)
		printf("Error in shared memory block\n");
	if (!execute_decoder(envp))
	{
		create_decompressed_file(&data);
		print_info(&data);
	}
	free_all(&data, 0, 0);
	return (0);
}
