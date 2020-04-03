/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include <iostream>
#include "Snake.hpp"

Snake::Snake(std::vector<arcade::Element> &map):
    _position({5, 5}),
    _element({path_sprite, arcade::GREEN, _position, arcade::Rect{Point{0, 0}, Point{0,0}}}),
    _size(1), _map(map), _alive(true) 
{}

Snake::~Snake()
{}

arcade::Element const& Snake::getElement() const
{
    return (_element);
}

void Snake::Move()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::duration<double> laps = now - _prevMove;

    if (laps.count() >= 0.05) {
        _position.x += _direction.x * 0.25;
        _position.y += _direction.y * 0.25;
        _element.position.x = _position.x;
        _element.position.y = _position.y;
        _prevMove = now;
    }
}

void Snake::setDirection(Point const &direction)
{
    _direction = direction;
}