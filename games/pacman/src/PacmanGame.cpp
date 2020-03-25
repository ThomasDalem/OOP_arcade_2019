/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#include <iostream>
#include "PacmanGame.hpp"
#include "Inputs.hpp"

extern "C" PacmanGame *createGame()
{
    return (new PacmanGame);
}

PacmanGame::PacmanGame()
{
    std::string strMap[6];
    std::string filename("../../games/pacman/assets/blue.png");

    strMap[0] = "**********";
    strMap[1] = "*        *";
    strMap[2] = "*  ** *  *";
    strMap[3] = "*  * **  *";
    strMap[4] = "*        *";
    strMap[5] = "**********";

    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 10; j++) {
            if (strMap[i][j] == '*') {
                arcade::Element element{filename, arcade::BLUE, Point{j, i}};
                _constElements.push_back(element);
            }
        }
    }
    _player = std::make_unique<Entity>(_constElements);
}

PacmanGame::~PacmanGame()
{}

void PacmanGame::playLoop(std::vector<arcade::Inputs> inputs)
{
    _elements.clear();
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::UP)
            _player->setDirection(Point{0, -1});
        else if (*it == arcade::DOWN)
            _player->setDirection(Point{0, 1});
        else if (*it == arcade::LEFT)
            _player->setDirection(Point{-1, 0});
        else if (*it == arcade::RIGHT)
            _player->setDirection(Point{1, 0});
    }
    _player->move();
    _elements.push_back(_player->getElement());
    _elements.insert(_elements.end(), _constElements.begin(), _constElements.end());
}

void PacmanGame::restart(void)
{

}

const std::vector<arcade::Element> &PacmanGame::getElements(void) const
{
    return (_elements);
}
