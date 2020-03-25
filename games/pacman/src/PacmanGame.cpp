/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#include <iostream>
#include "PacmanGame.hpp"

extern "C" PacmanGame *createGame()
{
    return (new PacmanGame);
}

PacmanGame::PacmanGame()
{}

PacmanGame::~PacmanGame()
{}

void PacmanGame::initGame(void)
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
        for (int j = 0; j < 9; j++) {
            if (strMap[i][j] == '*') {
                arcade::Element element{filename, arcade::BLUE, Point{i, j}};
                _elements.push_back(element);
            }
        }
    }
}

void PacmanGame::playLoop(void)
{

}

void PacmanGame::restart(void)
{

}

const std::vector<arcade::Element> &PacmanGame::getElements(void) const
{
    return (_elements);
}
