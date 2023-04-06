/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 18:25:05 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 05:53:20 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

void	printf_list(t_list *list)
{
	t_huffmanNode	*aux;

	aux = list->start;
	while (aux)
	{
		printf("%c freq %d\n", aux->c, aux->freq);
		aux = aux->next;
	}
}

void	print_huffman_tree(t_huffmanNode *node, int size)
{
	if (is_leaf(node))
		printf("Folha: %c, Altura: %d\n", node->c, size);
	else
	{
		print_huffman_tree(node->left, size + 1);
		print_huffman_tree(node->right, size + 1);
	}
}

void	print_mapping(t_data *data)
{
	int	i;

	printf("\nHuffman Mapping:\n");
	for (i = 0; i < NCHAR; i++)
	{
		if (data->freq[i] != 0)
			printf("%d - %c: %s\n", i, i, data->mapping[(int)i]);
	}
}
