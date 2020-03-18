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

    class Element {
        public:
            Element(color color, std::string &filename, Point pos);
            ~Element();

            color getColor(void) const;
            const std::string &getFilename(void) const;
            Point getPosition(void) const;

        private:
            std::string &_filename;
            color _color;
            Point _position;
    };
}

#endif /* !ELEMENT_HPP_ */
