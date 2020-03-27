/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include <iostream>
#include "Entity.hpp"

Entity::Entity(std::vector<arcade::Element> &map) :
    _isAlive(true),
    _direction(Point{0, 0}),
    _element(arcade::Element{std::string("./assets/sprites.png"), arcade::YELLOW, Point{1, 1},
            arcade::Rect{Point{62, 66}, Point{578, 0}}}),
    _map(map),
    _spriteManager(_element)
{}

Entity::Entity(Point direction, arcade::Element &element, std::vector<arcade::Element> &map) :
    _isAlive(true), _direction(direction), _element(element),
    _map(map), _spriteManager(_element)
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
    Point prevDirection = _direction;

    _direction = direction;
    _spriteManager.changeDirection(direction);
    if (!canMove())
        _direction = prevDirection;
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

bool Entity::canMove(void)
{
    for (auto it = _map.begin(); it != _map.end(); it++) {
        if (it->position.x == _element.position.x + _direction.x &&
            it->position.y == _element.position.y + _direction.y) {
            return (false);
        }
    }
    return (true);
}

void Entity::move(void)
{
    if (!canMove())
        return;
    _element.position.x += _direction.x;
    _element.position.y += _direction.y;
    _spriteManager.moveSprite();
}
