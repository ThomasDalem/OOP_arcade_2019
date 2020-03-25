/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include "Entity.hpp"

Entity::Entity() :
    _isAlive(true),
    _direction(RIGHT),
    _element(arcade::Element{std::string("./assets/pacman.png"), arcade::GREEN, Point{1, 1}})
{}

Entity::Entity(Point position, Direction direction, arcade::Element element) :
    _isAlive(true),
    _position(position),
    _direction(direction),
    _element(element)
{}

Entity::~Entity()
{}

Direction Entity::getDirection(void) const
{
    return (_direction);
}

const Point &Entity::getPosition(void) const
{
    return (_position);
}

bool Entity::isAlive(void) const
{
   return (_isAlive);
}

const arcade::Element &Entity::getElement(void) const
{
    return (_element);
}

void Entity::setDirection(Direction direction)
{
    _direction = direction;
}

void Entity::setPosition(const Point &position)
{
    _position = position;
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

void Entity::move(std::vector<std::string> map)
{
    map = map;
}
