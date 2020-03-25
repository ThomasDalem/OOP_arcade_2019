/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include <iostream>
#include "Entity.hpp"

Entity::Entity() :
    _isAlive(true),
    _direction(Point{0, 0}),
    _element(arcade::Element{std::string("./assets/pacman.png"), arcade::GREEN, Point{1, 1}})
{}

Entity::Entity(Point direction, arcade::Element element) :
    _isAlive(true),
    _direction(direction),
    _element(element)
{}

Entity::~Entity()
{}

Point Entity::getDirection(void) const
{
    return (_direction);
}

const Point &Entity::getPosition(void) const
{
    return (_element.position);
}

bool Entity::isAlive(void) const
{
   return (_isAlive);
}

const arcade::Element &Entity::getElement(void) const
{
    return (_element);
}

void Entity::setDirection(Point direction)
{
    _direction = direction;
}

void Entity::setPosition(const Point &position)
{
    _element.position = position;
}

void Entity::setStatus(bool isAlive)
{
    _isAlive = isAlive;
}

void Entity::setElement(arcade::Element &element)
{
    _element = element;
}

void Entity::move(std::vector<arcade::Element> &map)
{
    for (auto it = map.begin(); it != map.end(); it++) {
        if (it->position.x == _element.position.x + _direction.x &&
            it->position.y == _element.position.y + _direction.y) {
            return;
        }
    }
    _element.position.x += _direction.x;
    _element.position.y += _direction.y;
}
