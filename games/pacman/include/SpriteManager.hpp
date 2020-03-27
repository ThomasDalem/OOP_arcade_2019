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

const Point pacLeft = {580, 0};
const Point pacRight = {640, 0};
const Point pacUp = {580, 193};
const Point pacDown = {640, 193};

class SpriteManager {
    public:
        SpriteManager(arcade::Element &element);
        ~SpriteManager();

        void changeDirection(Point &dir);
        void moveSprite(void);

    private:
        arcade::Element &_element;
        Point _start;
        Point _pos;
};

#endif /* !SPRITEMANAGER_HPP_ */
