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

Nibbler::Nibbler():
    _apple({"./games/nibbler/assets/apple.png", arcade::RED, {5, 5}, arcade::Rect{{0, 0}, {0, 0}}})
{
    std::string strMap[11];
    const std::string path_wall("./games/pacman/assets/blue.png");

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
    strMap[10] = "****************";

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

int Nibbler::playLoop(std::vector<arcade::Inputs> const& inputs)
{
    std::vector<arcade::Element> snakeElem;

    _elements.clear();
    where(inputs);
    _snake->Move();
    snakeElem = _snake->getElements();
    _elements.insert(_elements.end(), _elements_const.begin(), _elements_const.end());
    _elements.insert(_elements.end(), snakeElem.begin(), snakeElem.end());
    return (100);
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

void Nibbler::where(std::vector<arcade::Inputs> const& inputs)
{
    for (auto it = inputs.begin(); it != inputs.end(); it++) {
        if (*it == arcade::UP)
            _snake->setDirection(Point{0, -1});
        else if (*it == arcade::DOWN)
            _snake->setDirection(Point{0, 1});
        else if (*it == arcade::LEFT)
            _snake->setDirection(Point{-1, 0});
        else if (*it == arcade::RIGHT)
            _snake->setDirection(Point{1, 0});
    }
}

void Nibbler::score(int nbApple)
{
    std::string text("Score: ");
    
    _text.clear();
    _score += nbApple * 100;
    text += std::to_string(_score);
    _text.push_back(arcade::Text{text, Point{15, 5}, arcade::BLUE});
}

/*
bool Nibbler::collide() const
{
    Point aTop = {_snake. .x + offset.x, _position.y + offset.y};
    Point aBottom = {_position.x + offset.x + 1.0f, _position.y + offset.y + 1.0f};
    Point bTop;
    Point bBottom;

    for (auto it = _map.begin(); it != _map.end(); it++) {
        bTop = {it->position.x, it->position.y};
        bBottom = {it->position.x + 1.0, it->position.y + 1.0};
        if (aTop.x < bBottom.x && aBottom.x > bTop.x && aTop.y < bBottom.y && aBottom.y > bTop.y) {
            return (false);
        }
    }
    return (true);
}*/
