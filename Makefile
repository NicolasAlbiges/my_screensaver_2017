##
## EPITECH PROJECT, 2017
## Makefile
## File description:
## Makefile for my_screensaver
##

CFLAGS	=	-I./include -W -Wall -Wextra -lcriterion

CFLAGS += -g3 

CC = gcc

SRC	=	id_one.c		\
		id_two.c		\
		id_three.c		\
		id_four.c		\
		id_five.c		\
		id_five_bis.c		\
		main.c		\
		circle.c		\
		draw_func_two.c		\
		draw_func_one.c		\

OBJ	=	$(SRC:.c=.o)

NAME	=	my_screensaver

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my
	$(CC) -o $(NAME) $(OBJ) -L./lib/my -lmy -lcsfml-graphics -lcsfml-system -lcsfml-window

clean:
	rm -f $(OBJ)
	make clean -C ./lib/my

fclean:	clean
	rm -f $(NAME)
	make fclean -C ./lib/my

re:	fclean all
