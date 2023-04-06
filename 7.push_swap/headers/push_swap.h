/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:23:23 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 00:23:47 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648

# include "../libft/libft.h"
# include "../ft_printf/ft_printf.h"

typedef struct s_element
{
	int					elem;
	int					index;
	struct s_element	*prev;
	struct s_element	*next;
}	t_element;

typedef struct s_stack
{
	t_element	*start;
	int			size;
}	t_stack;

typedef struct s_head
{
	int			head_elem;
	int			head_index;
}	t_head;

typedef struct s_move
{
	char			*move;
	struct s_move	*next;
}	t_move;

typedef struct s_movelist
{
	t_move	*start;
}	t_movelist;

typedef struct s_data
{
	int			*args;
	int			nargs;
	int			next_move;
	int			min_moves;
	t_head		head;
	t_stack		stack_a;
	t_stack		stack_b;
	t_stack		stack_aux;
	t_movelist	moves_list;
}	t_data;

int			init(t_data *data);
int			check_args(char *argv[], t_data *data);
int			check_duplicates(int *arr, int i, int n);
int			is_sorted(t_data *data, int free_if_sorted);
int			ft_error(int printerror, int e, t_data *data);
int			build_stacks(t_data *data);
void		add_elem_end_stack(t_stack *stack, t_element *elem);
void		add_elem_start_stack(t_stack *stack, t_element *new);
t_element	*remove_first_elem_stack(t_stack *stack);
t_element	*remove_last_elem_stack(t_stack *stack);
void		print_stack(t_stack stack);
void		free_stack(t_element *elem);
void		free_all(t_data *data);
void		swap_first_two(t_stack *stack);
void		push(t_stack *s1, t_stack *s2);
void		rotate(t_stack *stack);
void		reverse_rotate(t_stack *stack);
char		*sa(t_data *data);
char		*sb(t_data *data);
char		*ss(t_data *data);
char		*pa(t_data *data);
char		*pb(t_data *data);
char		*ra(t_data *data);
char		*rb(t_data *data);
char		*rr(t_data *data);
char		*rra(t_data *data);
char		*rrb(t_data *data);
char		*rrr(t_data *data);
int			stack_is_sorted(t_stack *stack);
void		indexation(t_data *data);
void		create_aux(t_data *data);
void		find_head_stack_a(t_data *data);
void		move_to_b(t_data *data);
void		add_move_list(t_data *data, char *move);
void		print_moves(t_data data);
void		free_moves_list(t_move *elem);
void		move_to_a(t_data *data);
void		adjust_a(t_data *data);
int			max_value_a(t_data *data);
int			min_value_a(t_data *data);
t_element	*find_nth_elem(int n, t_stack *stack);
void		sort(t_data *data);
void		sort_small(t_data *data);
int			find_min(int *arr, int size);
int			count_keep_in_a(t_data *data, int i);
void		find_max(int *arr, int size, t_data *data);
int			find_position(t_element *elem_b, t_data *data);
int			calculate_total_movements(int pos_a, int pos_b, t_data *data);
int			element_to_move(t_data *data);
int			check_if_keep_in_a(t_data *data, int elem_ref, int aux);
int			check_if_swap_a(t_data *data, int elem_ref, int aux, int i);
int			check_if_swap_a_end(t_data *data, int elem_ref, int aux);
int			move_elem_before_head(t_data *data, int elem_ref, int *aux, int i);
int			move_elem_after_head(t_data *data, int elem_ref, int aux);
void		move_to_a_aux(int first, int last, t_data *data);
void		move_i(int first, int sec, int last, t_data *data);
void		move_ii(int first, int sec, int last, t_data *data);

#endif
