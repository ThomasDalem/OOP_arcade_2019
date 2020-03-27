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
#include "IBehavior.hpp"
#include "SpriteManager.hpp"

class Entity {
    public:
        Entity(std::vector<arcade::Element> &map);
        Entity(
            Point direction,
            arcade::Element &element,
            std::vector<arcade::Element> &map
        );

        Point getDirection(void) const;
        const Point &getPosition(void) const;
        bool isAlive(void) const;
        const arcade::Element &getElement(void) const;

        void setDirection(Point direction);
        void setPosition(const Point &position);
        void setStatus(bool isAlive);
        void setElement(arcade::Element &element);

        bool canMove(void);
        virtual void move(void);

    protected:
        bool _isAlive;
        Point _direction;
        arcade::Element _element;
        std::vector<arcade::Element> &_map;
        SpriteManager _spriteManager;
};

#endif /* !ENTITY_HPP_ */
