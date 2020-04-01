/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#ifndef ENTITY_HPP_
#define ENTITY_HPP_

#include <vector>
#include <chrono>
#include "Element.hpp"
#include "IBehavior.hpp"
#include "SpriteManager.hpp"

static const std::string sprites = "./games/pacman/assets/sprites.png";

class Entity {
    public:
        Entity(
            Point direction,
            Point position,
            arcade::Element const& element,
            std::vector<arcade::Element> &map
        );

        Point getDirection(void) const;
        const Point &getPosition(void) const;
        const arcade::Element &getElement(void) const;

        virtual void setDirection(Point const& direction);
        void setPosition(Point const& position);
        void setElement(arcade::Element &element);

        bool canMove(Point offset);
        virtual void move(void);

    protected:
        Point _direction;
        Point _position;
        arcade::Element _element;
        std::vector<arcade::Element> &_map;
        SpriteManager _spriteManager;
        std::chrono::time_point<std::chrono::system_clock> _prevMove;
};

#endif /* !ENTITY_HPP_ */
