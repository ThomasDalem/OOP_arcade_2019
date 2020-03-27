/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/

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
}

Ghost::~Ghost()
{}

bool Ghost::canMove(void)
{
    for (auto it = _map.begin(); it != _map.end(); it++) {
        if (it->position.x == _element.position.x + _direction.x &&
            it->position.y == _element.position.y + _direction.y) {
            return (false);
        }
    }
    return (true);
}

void Ghost::move(void)
{
    setDirection(_behavior->chase(_element.position, _direction));
    if (!canMove())
        return;
    _element.position.x += _direction.x;
    _element.position.y += _direction.y;
    _position.x += _direction.x;
    _position.y += _direction.y;
}
