##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			=	src/main.cpp		\
				src/Core.cpp		\
				src/Menu.cpp

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Werror -Wextra -I./include --std=c++2a -lstdc++fs -g3

NAME		=	arcade

all: $(NAME)

$(NAME): $(OBJ)
		g++ -o $(NAME) $(OBJ) $(CPPFLAGS) -ldl -g3

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re all
