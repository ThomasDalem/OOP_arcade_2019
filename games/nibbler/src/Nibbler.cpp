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
                _elementsConst.push_back(elem);
            }
        }
    }
    _snake = std::make_unique<Snake>(_elementsConst);
}

Nibbler::~Nibbler()
{}

int Nibbler::playLoop(std::vector<arcade::Inputs> const& inputs)
{
    std::vector<arcade::Element> snakeElem;

    _elements.clear();
    if (_snake->getHasLost() == false) {
        where(inputs);
        _snake->move();
    }
    snakeElem = _snake->getElements();
    _elements.insert(_elements.end(), _elementsConst.begin(), _elementsConst.end());
    _elements.insert(_elements.end(), snakeElem.begin(), snakeElem.end());
    _elements.push_back(_apple);
    return (score);
}

void Nibbler::restart()
{}

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

void Nibbler::getScore()
{
    std::string text("Score: ");
    
    _text.clear();
    score += 100;
    text += std::to_string(score);
    _text.push_back(arcade::Text{text, Point{15, 5}, arcade::BLUE});
}

void Nibbler::apple()
{
    std::srand(std::time(nullptr));
    Point snakePos = _snake->getPosition();
    if (snakePos.x == _apple.position.x && snakePos.y == _apple.position.y) {
        getScore();
        _apple.position = {std::rand() % 10, std::rand() % 10};
    }
}

bool Nibbler::snakeCollide(Point const& obj) const
{
    return (_snake->getPosition().x == obj.x &&  _snake->getPosition().y == obj.y);
}