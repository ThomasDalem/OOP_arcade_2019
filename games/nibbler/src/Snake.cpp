/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include <iostream>
#include "Snake.hpp"

Snake::Snake(std::vector<arcade::Element> &map):
    _position({5, 5}),
    _element({path_sprite, arcade::GREEN, _position, arcade::Rect{Point{0, 0}, Point{0,0}}}),
    _size(1), _map(map), _alive(true) 
{}

Snake::~Snake()
{}

arcade::Element const& Snake::getElement() const
{
    return (_element);
}