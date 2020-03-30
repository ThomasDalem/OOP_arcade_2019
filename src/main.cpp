/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** main
*/

#include <iostream>
#include "Core.hpp"

int main(int argc, char **argv)
{
    if (argc != 2) {
        std::cerr << "Error usage: Missing graphical library" << std::endl;
        std::cerr << "Usage: ./arcade path_to_graphical_library" << std::endl;
        return (84);
    }
    arcade::Core core(argv[1]);
    core.arcade();
    return (0);
}
