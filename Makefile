##
## EPITECH PROJECT, 2018
## Makefile
## File description:
## Aurélien Vandaële <aurelien.vandaele@epitech.eu>
##

SRC	=	src/main.c			\
		src/navy.c			\
		src/packet/server.c		\
		src/packet/client.c		\
		src/packet/client_connected.c	\
		src/packet/server_connected.c	\
		src/packet/count_signals.c	\
		src/packet/change_array_hit.c	\
		src/print.c			\
		src/utils/get_next_line.c	\
		src/utils/to_free.c		\
		src/packet/handle_gnl.c		\
		src/game_is_finish.c		\
		src/parser.c			\
		src/hit_or_missed.c

NAME	=	navy

OBJ	=	$(SRC:.c=.o)

COMPIL	=	-lmy -Llib/my

CFLAGS	=	-W -Wall -Werror -Wextra -I include/ -g

all:		$(NAME)

$(NAME):	$(OBJ)
		make -C lib/my
		make clean -C lib/my
		gcc -o $(NAME) $(OBJ) $(COMPIL) $(CFLAGS)
		make clean

clean:
		rm -f $(OBJ)
		rm -rf *~ src/*~ src/packet/*~ src/utils/*~ include/*~ lib/*~ lib/my/*~
		rm -f vgcore*

fclean:		clean
		make fclean -C lib/my
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean
