##
## EPITECH PROJECT, 2020
## OOP_arcade_2019
## File description:
## Makefile
##

SRC			= 	src/SFMLDisplay/SFMLDisplay.cpp

OBJ			=	$(SRC:.cpp=.o)

CPPFLAGS	=	-Wall -Werror -Wextra -I./include/ -I../../include/ -lsfml-graphics

CC			=	g++

NAME		=	lib_arcade_sfml.so

GREEN		=	\033[32m
YELLOW		=	\033[33m
NO_COLOR	=	\033[0m

%.o: %.cpp
	@echo -e "$(YELLOW)Building object files...$(NO_COLOR)"
	g++ -o $@ -c -fPIC $< $(CPPFLAGS) -g3
	@echo -e "$(GREEN)Files building complete !$(NO_COLOR)"

$(NAME): all

all: $(OBJ)
	$(CC) -shared -o $(NAME) $(OBJ) -g3 -lsfml-graphics
	mv lib_arcade_sfml.so ../

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f ../$(NAME)

re: fclean all

.PHONY: all clean fclean re
