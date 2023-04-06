SRCS_PATH = ./srcs/
OBJS_PATH = ./objs/
HEADERS_PATH = ./headers/

SRC_FILES_ENCODER = main.c init_utils.c linked_list_utils.c read_files.c huffman_tree.c \
			mapping.c encode.c shared_memory_utils.c end_utils.c execute_decoder.c debug.c

SRC_FILES_DECODER = decode.c shared_memory_utils.c linked_list_utils.c huffman_tree.c debug.c

SRCS_ENCODER = $(addprefix $(SRCS_PATH), $(SRC_FILES_ENCODER))

SRCS_DECODER = $(addprefix $(SRCS_PATH), $(SRC_FILES_DECODER))

OBJ_FILES_ENCODER = $(patsubst %.c, %.o, $(SRC_FILES_ENCODER))

OBJ_FILES_DECODER = $(patsubst %.c, %.o, $(SRC_FILES_DECODER))

OBJS_ENCODER = $(addprefix $(OBJS_PATH), $(OBJ_FILES_ENCODER))

OBJS_DECODER = $(addprefix $(OBJS_PATH), $(OBJ_FILES_DECODER))

MKDIR = mkdir -p

NAME_ENCODER = encoder

NAME_DECODER = decoder

CC   = cc

CFLAGS = -Wall -Wextra -Werror -g -I $(HEADERS_PATH)

RM  =  rm -f

all: $(NAME_ENCODER) $(NAME_DECODER)

$(NAME_ENCODER): $(OBJS_ENCODER)
	$(CC) $(CFLAGS) -o $(NAME_ENCODER) $(OBJS_ENCODER)

$(NAME_DECODER): $(OBJS_DECODER)
	$(CC) $(CFLAGS) -o $(NAME_DECODER) $(OBJS_DECODER)

$(OBJS_PATH)%.o : $(SRCS_PATH)%.c
	@$(MKDIR) $(OBJS_PATH)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
		$(RM) $(OBJS_ENCODER) $(OBJS_DECODER)

fclean: clean
	    $(RM) $(NAME_ENCODER) $(NAME_DECODER)

re:   fclean all

.PHONY: all clean fclean re