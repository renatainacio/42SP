/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linked_list_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:18:17 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 18:56:40 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	create_list(t_list *list, unsigned int *freq)
{
	int				i;
	t_huffmanNode	*new_node;

	for (i = 0; i < NCHAR; i++)
	{
		if (freq[i] > 0)
		{
			new_node = (t_huffmanNode *)malloc(sizeof(t_huffmanNode));
			if (!new_node)
				return(-1);
			new_node->c = i;
			new_node->freq = freq[i];
			new_node->right = NULL;
			new_node->left = NULL;
			new_node->next = NULL;
			insert_node_in_list(list, new_node);
		}
	}
	return (0);
}

void	insert_node_in_list(t_list *list, t_huffmanNode *node)
{
	t_huffmanNode	*aux;

	if (list->start == NULL)
		list->start = node;
	else if (node->freq < list->start->freq)
	{
		node->next = list->start;
		list->start = node;
	}
	else
	{
		aux = list->start;
		while (aux->next && node->freq >= aux->next->freq)
			aux = aux->next;
		node->next = aux->next;
		aux->next = node;
	}
	list->size++;
}

void	remove_node_from_list_start(t_list *list)
{
	t_huffmanNode	*aux;

	if (list->start)
	{
		aux = list->start;
		list->start = list->start->next;
		aux->next = NULL;
		list->size--;
	}
}
