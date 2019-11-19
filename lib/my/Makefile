##
## EPITECH PROJECT, 2018
## Library : Makefile
## File description:
## Aurélien Vandaële <aurelien.vandaele@epitech.eu>
##

SRC	=	my_putchar.c		\
		my_putstr.c		\
		my_strlen.c		\
		my_atoi.c		\
		my_putstr_error.c	\
		my_strcmp.c		\
		my_putnbr.c		\
		my_str_to_word_array.c	\
		my_strdup.c		\
		array_cpy.c		\
		my_strcpy.c		\
		my_strlen_array.c	\
		my_free_array.c

OBJ	= 	$(SRC:.c=.o)

NAME	=	libmy.a

CFLAGS	=	 -I../../include/

all:		$(NAME)

$(NAME):	$(OBJ)
		ar rc $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)
		rm -f *~

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
