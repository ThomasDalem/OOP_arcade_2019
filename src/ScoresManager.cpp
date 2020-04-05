/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoresManager
*/

#include <iostream>
#include <fstream>
#include "ScoresManager.hpp"
#include "CoreException.hpp"

ScoresManager::ScoresManager(): _actualScore(Score{"Unknown", -1})
{
    try {
        retreiveScores();
    }
    catch(CoreException const& e) {
        std::cerr << e.what() << std::endl;
    }
}

ScoresManager::~ScoresManager()
{
    try {
        writeScores();
    }
    catch(CoreException const& e) {
        std::cerr << e.what() << std::endl;
    }
}

void ScoresManager::addScore(std::string const& name)
{
    setScorePlayerName(_actualScore, name);
    _actualScore.score = 0;
}

void ScoresManager::updateActualScore(int score)
{
    _actualScore.score = score;
}

void ScoresManager::registerActualScore()
{
    if (_actualScore.score > 0) {
        _scores.push_back(_actualScore);
    }
}

std::vector<Score> const& ScoresManager::getScores() const
{
    return (_scores);
}

void ScoresManager::retreiveScores()
{
    std::ifstream file;
    Score handle;

    file.open(scoresFile);
    if (file.is_open() == false) {
        throw (CoreException("Could not open score file"));
    }
    file.read((char*)&handle, sizeof(Score));
    while (!file.eof()) {
        _scores.push_back(handle);
        file.read((char *)&handle, sizeof(Score));
    }
    file.close();
}

void ScoresManager::writeScores() const
{
    std::ofstream file;
    Score score = {};

    file.open(scoresFile, std::ios::binary);
    if (file.is_open() == false) {
        throw (CoreException("Could not open or create score file"));
    }
    for (auto it = _scores.begin(); it != _scores.end(); it++) {
        setScorePlayerName(score, it->playerName);
        score.score = it->score;
        file.write((char *)&score, sizeof(Score));
    }
    file.close();
}

void ScoresManager::setScorePlayerName(Score &score, std::string const& str) const
{
    int i = 0;

    for (; i < 10 && i < static_cast<int>(str.size()); i++) {
        score.playerName[i] = str[i];
    }
    for (; i < 10; i++) {
        score.playerName[i] = '\0';
    }
}
