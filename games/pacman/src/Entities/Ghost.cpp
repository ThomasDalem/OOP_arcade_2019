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
    arcade::Element element, 
    std::vector<arcade::Element> &map,
    Entity &player
) :
    Entity(direction, element, map)
{
    _behavior = std::make_unique<RedBehavior>(map, player);
}

Ghost::~Ghost()
{}

void Ghost::move(void)
{
    setDirection(_behavior->chase(_element.position, _direction));
    if (!canMove())
        return;
    _element.position.x += _direction.x;
    _element.position.y += _direction.y;
}
