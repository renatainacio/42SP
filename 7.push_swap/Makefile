SRCS_PATH = ./srcs/
SRCS_PATH_BONUS = ./srcs_bonus/
OBJS_PATH = ./objs/
OBJS_PATH_BONUS = ./objs_bonus/
HEADERS_PATH = ./headers/
LIBFT_PATH = ./libft/
FT_PRINTF_PATH = ./ft_printf/

SRC_FILES = main.c check_args.c build_stacks.c push.c swap.c rotate.c reverse_rotate.c utils.c \
			stack_utils.c movement_utils.c sort.c sort_small.c min_max.c sort_utils.c \
			move_to_a_utils.c element_to_move.c moves_list_utils.c end_utils.c

SRC_FILES_BONUS = push_swap_bonus.c check_args_bonus.c build_stacks_bonus.c push_bonus.c \
				swap_bonus.c rotate_bonus.c reverse_rotate_bonus.c \
				get_next_line.c check_stacks_bonus.c end_utils_bonus.c

SRCS = $(addprefix $(SRCS_PATH), $(SRC_FILES))

SRCS_BONUS = $(addprefix $(SRCS_PATH_BONUS), $(SRC_FILES_BONUS))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))

OBJ_FILES_BONUS = $(patsubst %.c, %.o, $(SRC_FILES_BONUS))

OBJS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

OBJS_BONUS = $(addprefix $(OBJS_PATH_BONUS), $(OBJ_FILES_BONUS))

LIBFT_A = $(LIBFT_PATH)libft.a

LIBFT_PRINTF_A = $(FT_PRINTF_PATH)libftprintf.a

MKDIR = mkdir -p

NAME = push_swap

NAME_BONUS = checker

CC   = cc

CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_PATH) -g

RM  =  rm -f

all: $(NAME)

$(LIBFT_A):
	@cd $(LIBFT_PATH) && $(MAKE)

$(LIBFT_PRINTF_A):
	@cd $(FT_PRINTF_PATH) && $(MAKE)

$(NAME): $(LIBFT_A) $(LIBFT_PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf

$(NAME_BONUS): $(LIBFT_A) $(LIBFT_PRINTF_A) $(OBJS_BONUS)
	$(CC) $(CFLAGS) -o $(NAME_BONUS) $(OBJS_BONUS) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_PATH_BONUS)%.o : $(SRCS_PATH_BONUS)%.c
	@$(MKDIR) $(OBJS_PATH_BONUS)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)
		rm -rf ${OBJS_PATH} ${OBJS_PATH_BONUS}
		$(MAKE) clean -C $(LIBFT_PATH)
		$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean: clean
	    $(RM) $(NAME) $(BONUS)
		$(MAKE) fclean -C $(LIBFT_PATH)
		$(MAKE) fclean -C $(FT_PRINTF_PATH)

re:   fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re