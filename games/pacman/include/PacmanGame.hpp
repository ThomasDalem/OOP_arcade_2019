/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#ifndef PacmanGame_HPP_
#define PacmanGame_HPP_

#include <memory>
#include <chrono>
#include "IGameModule.hpp"
#include "Ghost.hpp"
#include "Player.hpp"

class PacmanGame : public arcade::IGameModule {
    public:
        PacmanGame();
        ~PacmanGame();

        void playLoop(std::vector<arcade::Inputs> inputs);
        void restart(void);
        const std::vector<arcade::Element> &getElements() const;

    private:
        std::chrono::duration<double> getElapsedTime(
            std::chrono::time_point<std::chrono::system_clock> start,
            std::chrono::time_point<std::chrono::system_clock> end
        ) const;

    private:
        std::vector<arcade::Element> _elements;
        std::vector<arcade::Element> _constElements;
        std::unique_ptr<Player> _player;
        std::unique_ptr<Ghost> _enemy;
};

#endif /* !PacmanGame_HPP_ */
