/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#include <iostream>
#include "Nibbler.hpp"

extern "C" Nibbler *createObject()
{
    return (new Nibbler);
}

Nibbler::Nibbler()
{
    std::string strMap[11];
    const std::string path_wall("./games/nibbler/assets/wall.jpg");

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

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 16; j++) {
            Point pos = {static_cast<double>(j), static_cast<double>(i)};
            if (strMap[i][j] == '*') {
                arcade::Element elem{path_wall, arcade::WHITE, pos, arcade::Rect{Point{0,0}, Point{0,0}}};
                _elements_const.push_back(elem);
            }
        }
    }
    _snake = std::make_unique<Snake>(_elements_const);
}

Nibbler::~Nibbler()
{}

void Nibbler::playLoop(std::vector<arcade::Inputs> const& inputs)
{
    if (inputs.size()) {
        std::cout << "bonjour" << std::endl;
    }
    _elements.clear();
    _elements.insert(_elements.end(), _elements_const.begin(), _elements_const.end());
    _elements.push_back(_snake->getElement());
}

void Nibbler::restart()
{
}

std::vector<arcade::Element> const& Nibbler::getElements() const
{
    return (_elements);
}

std::vector<arcade::Text> const& Nibbler::getTexts() const
{
    return (_text);
}