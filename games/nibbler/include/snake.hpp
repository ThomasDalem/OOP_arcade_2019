/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <vector>
#include <chrono>
#include "Element.hpp"

static const std::string path_sprite = "./games/pacman/assets/sprites.png";

class snake {
    public:
        snake();
        ~snake();
        
    private:
        Point _position;
        Point _direction;
        arcade::Element _element;
        size_t _size;
        std::vector<arcade::Element> &map;
        bool _alive;
};


#endif /* !SNAKE_HPP_ */
