CC        = gcc
CFLAGS    = -Wall -Wextra -Werror

NAME    = libftprintf.a
INCS    = includes

SRCS    =	ft_print_address.c ft_print_char.c ft_print_hexa.c ft_print_int.c \
			ft_print_string.c ft_printf.c ft_strlen.c

SRC_BONUS =	

OBJ    = ${SRCS:.c=.o}
OBJ_BONUS = $(SRC_BONUS:.c=.o)
LIBR    = ranlib

.c.o:
		${CC} ${CFLAGS} -I ./ -c $< -o ${<:.c=.o} -I ${INCS}

${NAME}: ${OBJ}
	ar rc ${NAME} ${OBJ}

all: ${NAME}

bonus: ${OBJ} ${OBJ_BONUS}
		ar rc ${NAME} ${OBJ} ${OBJ_BONUS}

clean:
		rm -f ${OBJ} ${OBJ_BONUS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY:	all clean fclean re bonus