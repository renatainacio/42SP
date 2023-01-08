SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
HEADERS_PATH = ./headers/
LIBFT_PATH = ./libft/
FT_PRINTF_PATH = ./ft_printf/

SRC_FILES = main.c end_utils.c init_utils.c cmd_utils.c run_pipex.c

SRCS = $(addprefix $(SRCS_PATH), $(SRC_FILES))

OBJ_FILES = $(patsubst %.c, %.o, $(SRC_FILES))

OBJS = $(addprefix $(OBJS_PATH), $(OBJ_FILES))

LIBFT_A = $(LIBFT_PATH)libft.a

LIBFT_PRINTF_A = $(FT_PRINTF_PATH)libftprintf.a

MKDIR = mkdir -p

NAME = pipex

CC   = cc

CFLAGS = -Wall -Wextra -Werror -I $(HEADERS_PATH)

RM  =  rm -f

all: $(NAME)

$(LIBFT_A):
	@cd $(LIBFT_PATH) && $(MAKE)

$(LIBFT_PRINTF_A):
	@cd $(FT_PRINTF_PATH) && $(MAKE)

$(NAME): $(LIBFT_A) $(LIBFT_PRINTF_A) $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) -L $(LIBFT_PATH) -lft -L $(FT_PRINTF_PATH) -lftprintf

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS)
		$(MAKE) clean -C $(LIBFT_PATH)
		$(MAKE) clean -C $(FT_PRINTF_PATH)

fclean: clean
	    $(RM) $(NAME)
		$(MAKE) fclean -C $(LIBFT_PATH)
		$(MAKE) fclean -C $(FT_PRINTF_PATH)

re:   fclean all

.PHONY: all clean fclean re