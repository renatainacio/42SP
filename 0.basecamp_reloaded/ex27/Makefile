SRC = ft_display_file.c

OBJS = ${SRC: .c=.o}

NAME = ft_display_file

CC   = gcc

CFLAGS = -Wall -Wextra -Werror

RM  =  rm -f

.c.o:
			${CC} ${CFLAGS} -c $< -o ${<:.c=.o} 

${NAME}: ${OBJS}
	${CC} -o ${NAME} ${OBJS}

all: ${NAME}

clean:
		${RM} *.o

fclean: clean
	      ${RM} ${NAME}

re:   fclean all

.PHONY: all clean fclean re