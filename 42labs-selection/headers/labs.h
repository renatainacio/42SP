/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   labs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:23:23 by rinacio           #+#    #+#             */
/*   Updated: 2023/01/15 19:05:31 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABS_H
# define LABS_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <string.h>
# include <sys/shm.h>
# include <time.h>
# include <sys/wait.h>

# define NCHAR 256
# define FILENAME "./srcs/main.c"

typedef struct s_huffmanNode
{
	unsigned char			c;
	unsigned int			freq;
	struct s_huffmanNode	*right;
	struct s_huffmanNode	*left;
	struct s_huffmanNode	*next;
}	t_huffmanNode;

typedef struct s_list
{
	t_huffmanNode	*start;
	unsigned int	size;
}	t_list;

typedef struct s_data
{
	int				*fd;
	int				nfiles;
	int				tree_height;
	int				encoded_size;
	unsigned char	ascii[NCHAR];
	unsigned int	*freq;
	unsigned int	*shared_data;
	char			**mapping;
	char			*encoded_str;
	unsigned char	*decoded_str;
	t_list			list;
}	t_data;

typedef struct s_decoder
{
	unsigned int	*freq;
	unsigned int	*shared_data;
	unsigned char	*decoded_str;
	t_list			list;	
}	t_decoder;

void			args_check(int argc, t_data *data);
int				open_files(char *argv[], t_data *data);
void			init_variables(t_data *data);
int				create_list(t_list *list, unsigned int *freq);
void			insert_node_in_list(t_list *list, t_huffmanNode *node);
void			remove_node_from_list_start(t_list *list);
int				build_huffman_tree(t_list *list);
void			printf_list(t_list *list);
int				is_leaf(t_huffmanNode *node);
void			print_huffman_tree(t_huffmanNode *node, int size);
void			alloc_mapping(int tree_height, t_data *data);
int				get_huffman_tree_height(t_huffmanNode *node);
void			generate_mapping(t_data *data, t_huffmanNode *node, char *aux);
void			get_frequency(t_data *data);
void			free_all(t_data *data, int breakpoint, int files);
void			print_mapping(t_data *data);
void			calculate_encoded_size(t_data *data);
void			encode(t_data *data, char *argv[]);
void			decode(t_data *data);
int				zip(t_data *data);
void			unzip(t_decoder *decoder);
void			close_files(t_data *data);
void			free_huffman_tree(t_huffmanNode *node);
unsigned int	*get_shared_memory(int size, int segment);
unsigned char	*get_shared_memory_str(int size, int segment);
int				execute_decoder(char *envp[]);
void			print_info(t_data *data);
int				clean_shm(char *envp[]);
void			create_decompressed_file(t_data *data);
int				get_memory_id(int size, int segment);
void			exit_message(char *msg, int exit_code);
void			free_decoder(t_decoder *decoder, int breakpoint);

#endif