/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rinacio <rinacio@student.42sp.org.br>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 20:23:23 by rinacio           #+#    #+#             */
/*   Updated: 2023/03/01 04:03:55 by rinacio          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# define INT_MAX 2147483647
# define INT_MIN -2147483648
# define BUFFER_SIZE 1

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

typedef struct s_data
{
	int			*args;
	int			nargs;
	t_stack		stack_a;
	t_stack		stack_b;
	char		*keeper;
	char		*next_line;
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
void		get_next_line(int fd, t_data *data);
int			apply_operations(t_data *data, char *operation, int len);
int			stack_is_empty(t_stack *stack);
void		print_stack(t_stack stack);
void		read_push_swap_instructions(t_data *data);
void		end_gnl(t_data *data);

#endif
