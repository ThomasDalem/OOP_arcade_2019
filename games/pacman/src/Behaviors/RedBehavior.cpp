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

Point RedBehavior::chase(Point const& pos, Point const& direction) const
{
    Point shortestDir{0, 0};
    int shortestDist = 999;
    Point prevDir = invertPoint(direction);

    for (int i = 0; i < 4; i++) {
        if (canMoveAt(pos, dirArray[i])) {
            if (dirArray[i].x == prevDir.x && dirArray[i].y == prevDir.y) {
                continue;
            }
            if (getDistance(_player.getPosition(), Point{pos.x + dirArray[i].x, pos.y + dirArray[i].y}) < shortestDist) {
                shortestDist = getDistance(_player.getPosition(), Point{pos.x + dirArray[i].x, pos.y + dirArray[i].y});
                shortestDir = dirArray[i];
            }
        }
    }
    return (shortestDir);
}

bool RedBehavior::canMoveAt(Point const& pos, Point const& direction) const
{
    for (auto it = _map.begin(); it != _map.end(); it++) {
        if (pos.x + direction.x == it->position.x &&
            pos.y + direction.y == it->position.y) {
            return (false);
        }
    }
    return (true);
}

int RedBehavior::getDistance(Point const& a, Point const& b) const
{
    int x = (b.x - a.x) * (b.x - a.x);
    int y = (b.y - a.y) * (b.y - a.y);

    return (sqrt(x + y));
}

bool RedBehavior::comparePoints(Point const& a, Point const& b) const
{
    if ((int)a.x != (int)b.x || (int)a.y != (int)b.y)
        return (false);
    return (true);
}

Point RedBehavior::invertPoint(Point const& a) const
{
    return (Point{a.x * -1, a.y * -1});
}
