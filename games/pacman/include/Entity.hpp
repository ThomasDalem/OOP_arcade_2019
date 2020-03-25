/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <string>
#include "Element.hpp"

enum Direction {
    UP,
    DOWN,
    LEFT,
    RIGHT
};

class Entity {
    public:
        Entity();
        Entity(Point position, Direction direction, arcade::Element element);
        ~Entity();

        Direction getDirection(void) const;
        const Point &getPosition(void) const;
        bool isAlive(void) const;
        const arcade::Element &getElement(void) const;

        void setDirection(Direction direction);
        void setPosition(const Point &position);
        void setStatus(bool isAlive);
        void setElement(arcade::Element &element);

        void move(std::vector<std::string> map);

    private:
        bool _isAlive;
        Point _position;
        Direction _direction;
        arcade::Element _element;
};

#endif /* !ENTITY_HPP_ */
