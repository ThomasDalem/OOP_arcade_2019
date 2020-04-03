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

$(NAME): core games graphicals

core: $(OBJ)
	g++ -o $(NAME) $(OBJ) $(CPPFLAGS) -ldl -g3

games:
	make -C ./games/pacman/

graphicals:
	make -C ./games/pacman/
	make -C ./lib/LIBCACA/
	make -C ./lib/SDL2/
	make -C ./lib/SFML/

clean:
	make clean -C ./games/pacman/
	make clean -C ./lib/LIBCACA/
	make clean -C ./lib/SDL2/
	make clean -C ./lib/SFML/
	rm -f $(OBJ)

fclean: clean
	make fclean -C ./games/pacman/
	make fclean -C ./lib/LIBCACA/
	make fclean -C ./lib/SDL2/
	make fclean -C ./lib/SFML/
	rm -f $(NAME)

re: fclean all

.PHONY: core games graphicals clean fclean re all
