/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteManager
*/

#include <iostream>
#include "SpriteManager.hpp"

SpriteManager::SpriteManager(arcade::Element &element) :
    _element(element), _start(pacRight), _pos(pacRight)
{}

SpriteManager::~SpriteManager()
{}

void SpriteManager::setStart(Point const& start)
{
    _start.x = start.x;
    _start.y = start.y;
    _pos.x = start.x;
    _pos.y = start.y;
}

void SpriteManager::changePacmanDirection(Point const& dir)
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

void SpriteManager::changeGhostDirection(Point const& dir)
{
    if (dir.x == 1) {
        _pos.y = ghostRight;
    } else if (dir.x == -1) {
        _pos.y = ghostLeft;
    } else if (dir.y == 1) {
        _pos.y = ghostDown;
    } else {
        _pos.y = ghostUp;
    }
    _start.y = _pos.y;
    _element.rect.pos.y = _pos.y;
}

void SpriteManager::movePacmanSprite()
{
    _element.rect.pos = _pos;
    if (_pos.y >= _start.y + 2 * 33) {
        _pos.y = _start.y;
        return;
    }
    _pos.y += 33;
}

void SpriteManager::moveGhostSprite()
{
    if (_pos.y >= _start.y + 32) {
        _pos.y = _start.y;
    } else {
        _pos.y += 32;
    }
    _element.rect.pos = _pos;
}
