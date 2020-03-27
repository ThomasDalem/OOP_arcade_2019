/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteManager
*/

#include "SpriteManager.hpp"

SpriteManager::SpriteManager(arcade::Element &element) :
    _element(element), _start(pacRight), _pos(pacRight)
{}

SpriteManager::~SpriteManager()
{}

void SpriteManager::changeDirection(Point &dir)
{
    Point newDir;

    if (dir.x == 1) {
        newDir = pacRight;
    } else if (dir.x == -1) {
        newDir = pacLeft;
    } else if (dir.y == 1) {
        newDir = pacDown;
    } else {
        newDir = pacUp;
    }
    _start = newDir;
    _pos = newDir;
    _element.rect.pos = _pos;
}

void SpriteManager::moveSprite(void)
{
    _element.rect.pos = _pos;
    if (_pos.y >= _start.y + 2 * 65) {
        _pos.y = _start.y;
        return;
    }
    _pos.y += 65;
}
