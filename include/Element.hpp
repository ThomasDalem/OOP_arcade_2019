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
        BLACK
    };

    struct Element {
        std::string filename;
        arcade::color color;
        Point position;
    };
}

#endif /* !ELEMENT_HPP_ */
