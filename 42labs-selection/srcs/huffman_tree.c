/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   huffman_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 02:14:59 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 19:09:28 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "labs.h"

int	build_huffman_tree(t_list *list)
{
	t_huffmanNode	*first_node;
	t_huffmanNode	*second_node;
	t_huffmanNode	*new_tree_node;

	while (list->size > 1)
	{
		first_node = list->start;
		second_node = first_node->next;
		new_tree_node = (t_huffmanNode *)malloc(sizeof(t_huffmanNode));
		if (!new_tree_node)
			return (-1);
		new_tree_node->c = 'x';
		new_tree_node->freq = first_node->freq + second_node->freq;
		new_tree_node->left = first_node;
		new_tree_node->right = second_node;
		new_tree_node->next = NULL;
		remove_node_from_list_start(list);
		remove_node_from_list_start(list);
		insert_node_in_list(list, new_tree_node);
	}
	return (get_huffman_tree_height(list->start));
}

int	get_huffman_tree_height(t_huffmanNode *node)
{
	int	right;
	int	left;

	if (node == NULL)
		return (-1);
	right = get_huffman_tree_height(node->right) + 1;
	left = get_huffman_tree_height(node->left) + 1;
	if (right > left)
		return (right);
	else
		return (left);
}

int	is_leaf(t_huffmanNode *node)
{
	if (node->left == NULL && node->right == NULL)
		return (1);
	else
		return (0);
}

void	free_huffman_tree(t_huffmanNode *node)
{
	if (is_leaf(node))
		free(node);
	else
	{
		free_huffman_tree(node->left);
		free_huffman_tree(node->right);
		free(node);
	}
}
