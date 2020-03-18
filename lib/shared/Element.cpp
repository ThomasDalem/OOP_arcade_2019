/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Element
*/

#include "Element.hpp"

using namespace arcade;

Element::Element(arcade::color color, std::string &filename, Point pos):
    _filename(filename),
    _color(color),
    _position(pos)
{}

Element::~Element()
{}

color Element::getColor(void) const
{
    return (_color);
}

Point Element::getPosition(void) const
{
    return (_position);
}

const std::string &Element::getFilename(void) const
{
    return (_filename);
}
