SRCS = srcs/ft_putchar srcs/ft_putstr srcs/ft_strcmp srcs/ft_strlen srcs/ft_swap

OBJS = ${SRCS: .c=.o}

INCL = includes

NAME = libft.a

LIBC = ar rc

LIBR = ranlib

CC   = gcc

CFLAGS = -Wall -Wextra -Werror -c -I ${INCL}

RM  =  rm -f

.c.o:
			${CC} ${CFLAGS} $< -o ${<:.c=.o} 

${NAME}: ${OBJS}
	${LIBC} ${NAME} ${OBJS}
	${LIBR} ${NAME}

all: ${NAME}

clean:
		${RM} ${OBJS}

fclean: clean
	      ${RM} ${NAME}

re:   fclean all

.PHONY: all clean fclean re