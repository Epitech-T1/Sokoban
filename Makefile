##
## EPITECH PROJECT, 2021
## delivery
## File description:
## Makefile
##

SRC =	src/main.c \
		src/sokoban.c \
		src/error_handling_map.c \
		src/usage.c \
		src/move_next.c \
		src/move.c \

OBJ = 	$(SRC:.c=.o)

NAME = 	my_sokoban

CFLAGS = -g

all: 	$(NAME)

$(NAME): 	$(OBJ)
		gcc -g -o $(NAME) $(OBJ) -lncurses

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re