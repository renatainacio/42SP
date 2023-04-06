/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared_memory_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 01:00:07 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 17:34:26 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	get_memory_id(int size, int segment)
{
	int	key;
	int	shared_memory_block_id;

	key = ftok(FILENAME, segment);
	if (key == -1)
	{
		printf("Error generating key of file\n");
		return (-1);
	}
	shared_memory_block_id = shmget(key, size, 0777 | IPC_CREAT);
	if (shared_memory_block_id == -1)
	{
		printf("shmget error\n");
		return (-1);
	}
	return (shared_memory_block_id);
}

unsigned int	*get_shared_memory(int size, int segment)
{
	int				shared_memory_block_id;
	unsigned int	*memory_block;

	shared_memory_block_id = get_memory_id(size, segment);
	memory_block = shmat(shared_memory_block_id, NULL, 0);
	if (!memory_block)
	{
		printf("shmat error\n");
		return (NULL);
	}
	return (memory_block);
}

unsigned char	*get_shared_memory_str(int size, int segment)
{
	int				shared_memory_block_id;
	unsigned char	*memory_block;

	shared_memory_block_id = get_memory_id(size, segment);
	memory_block = shmat(shared_memory_block_id, NULL, 0);
	if (!memory_block)
	{
		printf("shmat error\n");
		return (NULL);
	}
	return (memory_block);
}
