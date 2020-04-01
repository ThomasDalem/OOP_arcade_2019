/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Entity
*/

#include <iostream>
#include "Entity.hpp"

Entity::Entity(Point direction, Point position, arcade::Element const& element, std::vector<arcade::Element> &map) :
    _direction(direction), _position(position), _element(element),
    _map(map), _spriteManager(_element), _prevMove(std::chrono::system_clock::now())
{}

Point Entity::getDirection(void) const
{
    return (_direction);
}

const Point &Entity::getPosition(void) const
{
    return (_position);
}

const arcade::Element &Entity::getElement(void) const
{
    return (_element);
}

void Entity::setDirection(Point const &direction)
{
    if (!canMove(Point{direction.x * 0.25, direction.y * 0.25})) {
        return;
    }
    _direction = direction;
    _spriteManager.changePacmanDirection(direction);
}

void Entity::setPosition(const Point &position)
{
    _element.position = position;
    _position = position;
}

void Entity::setElement(arcade::Element &element)
{
    _element = element;
}

bool Entity::canMove(Point offset)
{
    Point aTop = {_position.x + offset.x, _position.y + offset.y};
    Point aBottom = {_position.x + offset.x + 1.0f, _position.y + offset.y + 1.0f};
    Point bTop;
    Point bBottom;

    for (auto it = _map.begin(); it != _map.end(); it++) {
        bTop = {it->position.x, it->position.y};
        bBottom = {it->position.x + 1.0, it->position.y + 1.0};
        if (aTop.x < bBottom.x && aBottom.x > bTop.x && aTop.y < bBottom.y && aBottom.y > bTop.y) {
            return (false);
        }
    }
    return (true);
}

void Entity::move(void)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = now - _prevMove;

    if (elapsedTime.count() >= 0.05) {
        if (!canMove(Point{_direction.x * 0.25, _direction.y * 0.25})) {
            return;
        }
        _position.x += _direction.x * 0.25;
        _position.y += _direction.y * 0.25;
        _element.position.x = _position.x;
        _element.position.y = _position.y;
        _prevMove = now;
        _spriteManager.movePacmanSprite();
    }
}
