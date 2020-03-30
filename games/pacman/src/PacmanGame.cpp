/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#include <iostream>
#include <chrono>
#include "PacmanGame.hpp"
#include "Inputs.hpp"

extern "C" PacmanGame *createObject()
{
    return (new PacmanGame);
}

PacmanGame::PacmanGame()
{
    std::string strMap[11];
    std::string filename("./games/pacman/assets/blue.png");

    strMap[0] = "****************";
    strMap[1] = "*              *";
    strMap[2] = "* ** ****** ** *";
    strMap[3] = "* *          * *";
    strMap[4] = "* * ** ** ** * *";
    strMap[5] = "*      **      *";
    strMap[6] = "* * ** ** ** * *";
    strMap[7] = "* *          * *";
    strMap[8] = "* ** ****** ** *";
    strMap[9] = "*              *";
    strMap[10] = "***************";

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 16; j++) {
            if (strMap[i][j] == '*') {
                arcade::Element element{filename, arcade::BLUE, Point{(float)j, (float)i}, arcade::Rect{Point{0, 0}, Point{0, 0}}};
                _constElements.push_back(element);
            }
        }
    }
    _player = std::make_unique<Player>(_constElements);
    _enemy = std::make_unique<Ghost>(
        Point{-1, 0},
        Point{14, 9},
        arcade::Element{"./games/pacman/assets/sprites.png", arcade::RED, Point{14, 9}, arcade::Rect{Point{32, 33}, Point{480, 0}}},
        _constElements,
        *_player
    );
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
    _enemy->move();
    _player->move();
    _elements.push_back(_player->getElement());
    _elements.push_back(_enemy->getElement());
    _elements.insert(_elements.end(), _constElements.begin(), _constElements.end());
}

void PacmanGame::restart(void)
{

}

const std::vector<arcade::Element> &PacmanGame::getElements(void) const
{
    return (_elements);
}

std::chrono::duration<double> getElapsedTime(std::chrono::time_point<std::chrono::system_clock> start,
                                             std::chrono::time_point<std::chrono::system_clock> end)
{
    std::chrono::duration<double> elapsedSeconds = end - start;

    return (elapsedSeconds);
}
