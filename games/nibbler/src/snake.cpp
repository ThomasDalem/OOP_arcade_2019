/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** snake
*/

#include <iostream>
#include "snake.hpp"

snake::snake()
{
    _position = {5, 5};
    _size = 1;
    arcade::Element{path_sprite, arcade::GREEN, _position, arcade::Rect{Point{0, 0}, Point{0,0}}};
    _alive = true;
}

snake::~snake()
{

}

