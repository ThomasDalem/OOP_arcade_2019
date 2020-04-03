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
        if (!canMove(Point{_direction.x * 0.25, _direction.y * 0.25})) {
            return;
        }
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

bool Snake::canMove(Point offset)
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