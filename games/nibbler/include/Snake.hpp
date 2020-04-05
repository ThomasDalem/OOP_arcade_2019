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

static const std::string pathSprite = "./games/nibbler/assets/green.jpg";

class Snake {
    public:
        Snake(std::vector<arcade::Element> &map);
        ~Snake();

        Point const& getPosition() const;
        std::vector<arcade::Element> const& getElements() const;
        bool getHasLost() const;
        void setDirection(Point const &direction);

        void move();
        void addTail();

    private:
        void moveTail();
        bool isColliding() const;

    private:
        Point _position;
        Point _direction;
        std::vector<arcade::Element> _elements;
        Point _lastTailPos;
        size_t _size;
        std::vector<arcade::Element> &_map;
        std::chrono::time_point<std::chrono::system_clock> _prevMove;
        bool _hasLost;
};

#endif /* !SNAKE_HPP_ */
