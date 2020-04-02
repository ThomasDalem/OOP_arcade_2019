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
#include "snake.hpp"

class nibbler : public arcade::IGameModule {
    public:
        nibbler();
        ~nibbler();
        void playloop(std::vector<arcade::Inputs> inputs);
        void restart (void);
        const std::vector<arcade::Element> &getElements() const;

    private:
        std::chrono::duration<double> getElapsedTime(
            std::chrono::time_point<std::chrono::system_clock> start,
            std::chrono::time_point<std::chrono::system_clock> end
        ) const;
        std::vector<arcade::Element> _element;
        std::vector<arcade::Element> _element_const;
        std::unique_ptr<snake> _snake;

        
}

#endif /* !NIBBLER_HPP_ */
