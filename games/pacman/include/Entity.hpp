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

class Entity {
    public:
        Entity();
        Entity(Point direction, arcade::Element element);
        ~Entity();

        Point getDirection(void) const;
        const Point &getPosition(void) const;
        bool isAlive(void) const;
        const arcade::Element &getElement(void) const;

        void setDirection(Point direction);
        void setPosition(const Point &position);
        void setStatus(bool isAlive);
        void setElement(arcade::Element &element);

        void move(std::vector<arcade::Element> &map);

    private:
        bool _isAlive;
        Point _direction;
        arcade::Element _element;
};

#endif /* !ENTITY_HPP_ */
