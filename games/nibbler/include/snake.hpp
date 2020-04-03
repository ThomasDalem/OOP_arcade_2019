/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Snake
*/

#ifndef SNAKE_HPP_
#define SNAKE_HPP_

#include <vector>
#include <chrono>
#include "Element.hpp"

static const std::string path_sprite = "./games/pacman/assets/sprites.png";

class Snake {
    public:
        Snake(std::vector<arcade::Element> &map);
        ~Snake();

        arcade::Element const& getElement() const;
    private:
        Point _position;
        Point _direction;
        arcade::Element _element;
        size_t _size;
        std::vector<arcade::Element> &_map;
        bool _alive;
};


#endif /* !SNAKE_HPP_ */
