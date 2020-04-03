/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacgumManager
*/

#include <iostream>
#include "PacgumManager.hpp"

PacgumManager::PacgumManager()
{}

PacgumManager::~PacgumManager()
{}

std::vector<arcade::Element> const& PacgumManager::getGums() const
{
    return (_gums);
}

void PacgumManager::addGum(Point const& position)
{
    arcade::Element newGum{spritesFile, arcade::YELLOW, position, arcade::Rect{Point{32, 33}, Point{0, 0}}};

    _gums.push_back(newGum);
}

int PacgumManager::removeTouchedGums(Point const& position)
{
    for (auto it = _gums.begin(); it != _gums.end(); it++) {
        if (collide(position, it->position)) {
            _gums.erase(it);
            return (1);
        }
    }
    return (0);
}

bool PacgumManager::areGumsEmpty() const
{
    return (_gums.size() == 0);
}

bool PacgumManager::collide(Point const& a, Point const& b) const
{
    Point aTop = {a.x, a.y};
    Point aBottom = {a.x + 1, a.y + 1};
    Point bTop = {b.x + 0.25, b.y + 0.25};
    Point bBottom = {b.x + 0.75, b.y + 0.75};

    if (aTop.x < bBottom.x && aBottom.x > bTop.x && aTop.y < bBottom.y && aBottom.y > bTop.y) {
        return (true);
    }
    return (false);
}
