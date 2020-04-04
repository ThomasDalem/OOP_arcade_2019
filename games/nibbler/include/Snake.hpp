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

static const std::string path_sprite = "./games/nibbler/assets/green.jpg";

class Snake {
    public:
        Snake(std::vector<arcade::Element> &map);
        ~Snake();
        void Move();
        bool canMove(Point offset);
        arcade::Element const& getElement() const;
        void setDirection(Point const &direction);
    private:
        Point _position;
        Point _direction;
        arcade::Element _element;
        size_t _size;
        std::vector<arcade::Element> &_map;
        bool _alive;
        std::chrono::time_point<std::chrono::system_clock> _prevMove;

};


#endif /* !SNAKE_HPP_ */
