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

PacmanGame::PacmanGame() : _score(0)
{
    std::string strMap[11];
    const std::string wallFile("./games/pacman/assets/blue.png");

    strMap[0] = "****************";
    strMap[1] = "*..............*";
    strMap[2] = "*.**.******.**.*";
    strMap[3] = "*.*..........*.*";
    strMap[4] = "*.* ** ** ** *.*";
    strMap[5] = "*......**......*";
    strMap[6] = "*.* ** ** ** *.*";
    strMap[7] = "*.*..........*.*";
    strMap[8] = "*.**.******.**.*";
    strMap[9] = "*..............*";
    strMap[10] = "****************";

    for (int i = 0; i < 11; i++) {
        for (int j = 0; j < 16; j++) {
            Point pos = {(double)j, (double)i};
            if (strMap[i][j] == '*') {
                arcade::Element element{wallFile, arcade::BLUE, pos, arcade::Rect{Point{0, 0}, Point{0, 0}}};
                _constElements.push_back(element);
            } else if (strMap[i][j] == '.') {
                _gumsManager.addGum(pos);
            }
        }
    }
    _player = std::make_unique<Player>(_constElements);
    _enemy = std::make_unique<Ghost>(
        Point{-1, 0},
        Point{14, 9},
        arcade::Element{sprites, arcade::RED, Point{14, 9}, arcade::Rect{Point{32, 33}, Point{480, 0}}},
        _constElements,
        *_player
    );
}

PacmanGame::~PacmanGame()
{}

void PacmanGame::playLoop(std::vector<arcade::Inputs> const& inputs)
{
    std::vector<arcade::Element> gums = _gumsManager.getGums();

    _elements.clear();
    _elements.insert(_elements.end(), gums.begin(), gums.end());
    if (collide(_player->getPosition(), _enemy->getPosition())) {
        _player->playLoose();
    } else {
        manageInputs(inputs);
        _enemy->move();
        _player->move();
        _elements.push_back(_enemy->getElement());
        setScore(_gumsManager.removeTouchedGums(_player->getPosition()));
    }
    _elements.push_back(_player->getElement());
    _elements.insert(_elements.end(), _constElements.begin(), _constElements.end());
}

void PacmanGame::restart()
{

}

const std::vector<arcade::Element> &PacmanGame::getElements() const
{
    return (_elements);
}

const std::vector<arcade::Text> &PacmanGame::getTexts() const
{
    return (_texts);
}

std::chrono::duration<double> getElapsedTime(std::chrono::time_point<std::chrono::system_clock> start,
                                             std::chrono::time_point<std::chrono::system_clock> end)
{
    std::chrono::duration<double> elapsedSeconds = end - start;

    return (elapsedSeconds);
}

bool PacmanGame::collide(Point const& a, Point const& b) const
{
    Point aTop = {a.x, a.y};
    Point aBottom = {a.x + 1, a.y + 1};
    Point bTop = {b.x, b.y};
    Point bBottom = {b.x + 1, b.y + 1};

    if (aTop.x < bBottom.x && aBottom.x > bTop.x && aTop.y < bBottom.y && aBottom.y > bTop.y) {
        return (true);
    }
    return (false);
}

void PacmanGame::manageInputs(std::vector<arcade::Inputs> const& inputs)
{
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
}

void PacmanGame::setScore(int removedGums)
{
    std::string scoreText("Score: ");

    if (!removedGums) {
        return;
    }
    _texts.clear();
    _score += removedGums * 100;
    scoreText += std::to_string(_score);
    _texts.push_back(arcade::Text{scoreText, Point{17, 2}, arcade::BLACK});
}
