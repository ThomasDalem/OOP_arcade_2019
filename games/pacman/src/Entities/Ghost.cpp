/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/

#include <iostream>
#include "RedBehavior.hpp"
#include "Ghost.hpp"

Ghost::Ghost(
    Point direction,
    Point position,
    arcade::Element element, 
    std::vector<arcade::Element> &map,
    Entity &player
) :
    Entity(direction, position, element, map)
{
    _behavior = std::make_unique<RedBehavior>(map, player);
    _spriteManager.setStart(Point{480, 0});
    _element.rect.pos.x = 480;
}

Ghost::~Ghost()
{}

void Ghost::setDirection(Point const& direction)
{
    if (!canMove(Point{direction.x * 0.25, direction.y * 0.25})) {
        return;
    }
    _direction = direction;
    _spriteManager.changeGhostDirection(direction);
}

void Ghost::move(void)
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::duration<double> elapsedTime = now - _prevMove;
    Point newDir;

    if (elapsedTime.count() >= 0.05) {
        newDir = _behavior->chase(_element.position, _direction);
        if (newDir.x != _direction.x || newDir.y != _direction.y) {
            setDirection(newDir);
        }
        if (!canMove(Point{_direction.x * 0.25, _direction.y * 0.25})) {
            return;
        }
        _position.x += _direction.x * 0.25;
        _position.y += _direction.y * 0.25;
        _element.position.x = _position.x;
        _element.position.y = _position.y;
        _prevMove = now;
        _spriteManager.moveGhostSprite();
    }
}
