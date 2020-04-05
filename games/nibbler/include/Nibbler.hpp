/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** nibbler
*/

#ifndef NIBBLER_HPP_
#define NIBBLER_HPP_

#include <memory>
#include <chrono>
#include "IGameModule.hpp"
#include "Snake.hpp"

class Nibbler : public arcade::IGameModule {
    public:
        Nibbler();
        ~Nibbler();

        int playLoop(std::vector<arcade::Inputs> const& inputs);
        void restart();
        std::vector<arcade::Element> const& getElements() const;
        std::vector<arcade::Text> const& getTexts() const;
        void where(std::vector<arcade::Inputs> const& inputs);
        void getScore();
        void apple();
        void getScore();
    private:
        bool snakeCollide(Point const& obj) const;

    private:
        std::vector<arcade::Element> _elements;
        std::vector<arcade::Element> _elementsConst;
        std::vector<arcade::Text> _text;
        std::unique_ptr<Snake> _snake;
        arcade::Element _apple;
        int score;
};
#endif /* !NIBBLER_HPP_ */
