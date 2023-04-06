/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapping.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 18:59:32 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 19:00:19 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	alloc_mapping(int tree_height, t_data *data)
{
	int	i;

	data->mapping = (char **)malloc(sizeof(char *) * (NCHAR));
	if (!data->mapping)
	{
		free_all(data, 2, 1);
		exit_message("Memory allocation error in build Huffman tree.", -1);
	}
	for (i = 0; i < NCHAR; i++)
	{
		data->mapping[i] = calloc(tree_height + 1, sizeof(char));
		if(!data->mapping[i])
		{
			free_all(data, 3, 1);
			exit_message("Memory allocation error in build Huffman tree.", -1);
		}
	}
}

void	generate_mapping(t_data *data, t_huffmanNode *node, char *aux)
{
	char	left[data->tree_height + 1];
	char	right[data->tree_height + 1];

	if (is_leaf(node))
	{
		strcpy(data->mapping[node->c], aux);
	}
	else
	{
		strcpy(left, aux);
		strcpy(right, aux);
		strcat(left, "0");
		strcat(right, "1");
		generate_mapping(data, node->left, left);
		generate_mapping(data, node->right, right);
	}
}
