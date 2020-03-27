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
    _position(Point{2, 2}),
    _element(arcade::Element{std::string("./assets/sprites.png"), arcade::YELLOW, Point{2, 2},
            arcade::Rect{Point{32, 33}, Point{289, 0}}}),
    _map(map),
    _spriteManager(_element)
{}

Entity::Entity(Point direction, Point position, arcade::Element &element, std::vector<arcade::Element> &map) :
    _isAlive(true), _direction(direction), _position(position), _element(element),
    _map(map), _spriteManager(_element)
{}

Point Entity::getDirection(void) const
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

void Entity::setDirection(Point direction)
{
    if (!canMove(Point{direction.x * 0.25, direction.y * 0.25})) {
        return;
    }
    _direction = direction;
    _spriteManager.changeDirection(direction);
}

void Entity::setPosition(const Point &position)
{
    _element.position = position;
    _position = position;
}

void Entity::setStatus(bool isAlive)
{
    _isAlive = isAlive;
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

    if (elapsedTime.count() > 0.1) {
        if (!canMove(Point{_direction.x * 0.25, _direction.y * 0.25})) {
            return;
        }
        _position.x += _direction.x * 0.25;
        _position.y += _direction.y * 0.25;
        _element.position.x = _position.x;
        _element.position.y = _position.y;
        _prevMove = now;
        _spriteManager.moveSprite();
    }
}