SRCS = ft_printf.c ft_putchar.c ft_putnbr.c ft_putstr.c ft_puthex.c ft_itoa.c\
		 	ft_putptr.c ft_aux.c ft_printf_utils.c ft_putuphex.c

SRCS_BONUS =  ft_printf_bonus.c ft_putchar_bonus.c ft_putnbr_bonus.c ft_putstr_bonus.c \
					ft_puthex_bonus.c ft_itoa_bonus.c ft_putptr_bonus.c ft_aux_bonus.c \
					ft_printf_utils_bonus.c ft_putuphex_bonus.c 

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

NAME = libftprintf.a

NAME_BONUS = libftprintfbonus.a

CC   = cc

CFLAGS = -Wall -Wextra -Werror -I.

RM  =  rm -f

.c.o:
	$(CC) -c $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	ar rc $(NAME) $(OBJS)

$(NAME_BONUS): $(OBJS_BONUS)
	ar rcs $(NAME) $(OBJS_BONUS)

all: $(NAME)

clean:
		$(RM) $(OBJS) $(OBJS_BONUS)

fclean: clean
	      $(RM) $(NAME) $(NAME_BONUS)

re:   fclean all

bonus: $(NAME_BONUS)

.PHONY: all clean fclean re