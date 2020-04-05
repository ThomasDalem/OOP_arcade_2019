/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include <iostream>
#include "Snake.hpp"

Snake::Snake(std::vector<arcade::Element> &map):
    _position({5, 5}), _size(1), _map(map), _hasLost(false)
{
    _elements.push_back({pathSprite, arcade::GREEN, _position, arcade::Rect{{0, 0}, {0,0}}});
    _elements.push_back({pathSprite, arcade::GREEN, {_position.x - 1, _position.y}, arcade::Rect{{0, 0}, {0, 0}}});
    _elements.push_back({pathSprite, arcade::GREEN, {_position.x - 2, _position.y}, arcade::Rect{{0, 0}, {0, 0}}});
}

Snake::~Snake()
{}

Point const& Snake::getPosition() const
{
    return (_position);
}

std::vector<arcade::Element> const& Snake::getElements() const
{
    return (_elements);
}

bool Snake::getHasLost() const
{
    return (_hasLost);
}

void Snake::move()
{
    std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    std::chrono::duration<double> laps = now - _prevMove;

    if (laps.count() >= 0.12) {
        if (_direction.x != 0 || _direction.y != 0) {
            moveTail();
        }
        _position.x += _direction.x;
        _position.y += _direction.y;
        _elements[0].position.x = _position.x;
        _elements[0].position.y = _position.y;
        if (isColliding()) {
            _hasLost = true;
        }
        _prevMove = now;
    }
}

void Snake::setDirection(Point const &direction)
{
    Point invertedDirection = {_direction.x * -1, _direction.y * -1};

    if (direction.x == invertedDirection.x && direction.y == invertedDirection.y)
        return;
    _direction = direction;
}

void Snake::addTail()
{
    _elements.push_back({pathSprite, arcade::GREEN, _lastTailPos, arcade::Rect{{0, 0}, {0, 0}}});
}

void Snake::moveTail()
{
    Point posSave;
    Point prevPos = _elements[0].position;

    for (auto it = _elements.begin(); it != _elements.end(); it++) {
        posSave = it->position;
        it->position = prevPos;
        prevPos = posSave;
    }
    _lastTailPos = posSave;
}

bool Snake::isColliding() const
{
    for (auto it = _map.begin(); it != _map.end(); it++) {
        if (_position.x == it->position.x && _position.y == it->position.y) {
            return (true);
        }
    }
    for (auto it = _elements.begin() + 1; it != _elements.end(); it++) {
        if (_position.x == it->position.x && _position.y == it->position.y) {
            return (true);
        } 
    }
    return (false);
}
