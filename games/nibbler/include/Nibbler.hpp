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

        void playLoop(std::vector<arcade::Inputs> const& inputs);
        void restart();
        std::vector<arcade::Element> const& getElements() const;
        std::vector<arcade::Text> const& getTexts() const;

    private:
        std::vector<arcade::Element> _elements;
        std::vector<arcade::Element> _elements_const;
        std::vector<arcade::Text> _text;
        std::unique_ptr<Snake> _snake;        
};
#endif /* !NIBBLER_HPP_ */