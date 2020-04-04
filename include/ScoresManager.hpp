/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** ScoresManager
*/

#ifndef SCORESMANAGER_HPP_
#define SCORESMANAGER_HPP_

#include <vector>
#include "Score.hpp"

static const std::string scoresFile("./scores.txt");

class ScoresManager {
    public:
        ScoresManager();
        ~ScoresManager();

        void addScore(std::string const& name, int score);
        std::vector<Score> const& getScores() const;

    private:
        void retreiveScores();
        void writeScores() const;
        void setScorePlayerName(Score &score, std::string const& str) const;

    private:
        std::vector<Score> _scores;
};

#endif /* !SCORESMANAGER_HPP_ */
