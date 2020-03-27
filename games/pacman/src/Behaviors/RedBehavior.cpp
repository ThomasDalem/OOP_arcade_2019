/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** RedBehavior
*/

#include <iostream>
#include <cmath>
#include "RedBehavior.hpp"

RedBehavior::RedBehavior(std::vector<arcade::Element> &map, Entity &player) :
    _map(map), _player(player)
{}

RedBehavior::~RedBehavior()
{}

Point RedBehavior::chase(Point &pos, Point &direction) const
{
    Point shortestDir{0, 0};
    int shortestDist = 999;
    direction = direction;
    for (int i = 0; i < 4; i++) {
        if (canMoveAt(pos, dirArray[i])) {
            if (getDistance(_player.getPosition(), Point{pos.x + dirArray[i].x, pos.y + dirArray[i].y}) < shortestDist) {
                shortestDist = getDistance(_player.getPosition(), Point{pos.x + dirArray[i].x, pos.y + dirArray[i].y});
                shortestDir = dirArray[i];
            }
        }
    }
    return (shortestDir);
}

bool RedBehavior::canMoveAt(Point pos, Point direction) const
{
    for (auto it = _map.begin(); it != _map.end(); it++) {
        if (pos.x + direction.x == it->position.x &&
            pos.y + direction.y == it->position.y) {
            return (false);
        }
    }
    return (true);
}

int RedBehavior::getDistance(Point a, Point b) const
{
    int x = (b.x - a.x) * (b.x - a.x);
    int y = (b.y - a.y) * (b.y - a.y);

    return (sqrt(x + y));
}

bool RedBehavior::comparePoints(Point a, Point b) const
{
    if ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
        return (false);
    return (true);
}

Point RedBehavior::invertPoint(Point a) const
{
    return (Point{a.x * -1, a.y * -1});
}
