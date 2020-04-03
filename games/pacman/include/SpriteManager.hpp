/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SpriteManager
*/

#ifndef SPRITEMANAGER_HPP_
#define SPRITEMANAGER_HPP_

#include "Element.hpp"
#include "Point.hpp"

static const Point pacLeft = {290, 0};
static const Point pacRight = {320, 0};
static const Point pacUp = {290, 97};
static const Point pacDown = {320, 97};

static const int ghostUp = 192;
static const int ghostDown = 65;
static const int ghostLeft = 128;
static const int ghostRight = 0;

class SpriteManager {
    public:
        SpriteManager(arcade::Element &element);
        ~SpriteManager();

        void setStart(Point const& start);

        void changePacmanDirection(Point const& dir);
        void changeGhostDirection(Point const& dir);
        void movePacmanSprite();
        void moveGhostSprite();

    private:
        arcade::Element &_element;
        Point _start;
        Point _pos;
};

#endif /* !SPRITEMANAGER_HPP_ */
