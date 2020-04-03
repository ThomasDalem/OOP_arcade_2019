/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/
#include <iostream>
#include <chrono>
#include "nibbler.hpp"

nibbler::nibbler()
{
    std::string strMap[11];
    std::string path_wall("./games/nibbler/assets/wall.jpg");

    strMap[0] = "****************";
    strMap[1] = "*              *";
    strMap[2] = "*              *";
    strMap[3] = "*              *";
    strMap[4] = "*              *";
    strMap[5] = "*              *";
    strMap[6] = "*              *";
    strMap[7] = "*              *";
    strMap[8] = "*              *";
    strMap[9] = "*              *";
    strMap[10] = "***************";

    for (int i = 0, i < 11, i++) {
        for (int j = 0, j < 16, j++) {
            Point pos = {(double)j, (double)i};
            if (strMap[i][j] == '*') {
                arcade::Element elem{path_wall, arcade::WHITE, pos, arcade::Rect{Point{0,0}, Point{0,0}}};
                _element_const.push_back(elem);
        }
    }
    _snake = std::make_unique<snake>(_element);

}

nibbler::~nibbler()
{
}

void nibbler::playLoop(std::vector<arcade::Inputs> const& inputs)
{
    _elements.clear();
    _elements.insert(_elements.end());
    _elements.push_back(_snake.getElement());
    _elements.insert(_element.end(), _element_const.begin(), _element_const());
}

void nibbler::restart()
{
}

const std::vector<arcade::Element> &nibbler::getElements() const
{
    return (_element);
}