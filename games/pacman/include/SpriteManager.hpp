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

const Point pacLeft = {290, 0};
const Point pacRight = {320, 0};
const Point pacUp = {290, 97};
const Point pacDown = {320, 97};

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
