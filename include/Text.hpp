/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Text
*/

#ifndef TEXT_HPP_
#define TEXT_HPP_

#include <string>
#include "Point.hpp"
#include "Element.hpp"

namespace arcade {
    struct Text {
        std::string text;
        Point pos;
        Color background;
    };
};

#endif /* !TEXT_HPP_ */
