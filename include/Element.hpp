/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Element
*/

#ifndef ELEMENT_HPP_
#define ELEMENT_HPP_

#include <string>
#include "Point.hpp"

namespace arcade {
    enum color {
        WHITE,
        RED,
        BLUE,
        GREEN,
        YELLOW,
        BLACK
    };

    struct Rect {
        Point size;
        Point pos;
    };

    struct Element {
        std::string filename;
        arcade::color color;
        Point position;
        Rect rect;
    };
}

#endif /* !ELEMENT_HPP_ */
