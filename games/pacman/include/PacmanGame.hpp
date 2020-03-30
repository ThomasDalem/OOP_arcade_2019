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
#include "PacgumManager.hpp"

class PacmanGame : public arcade::IGameModule {
    public:
        PacmanGame();
        ~PacmanGame();

        void playLoop(std::vector<arcade::Inputs> const& inputs);
        void restart(void);
        std::vector<arcade::Element> const& getElements() const;

    private:
        std::chrono::duration<double> getElapsedTime(
            std::chrono::time_point<std::chrono::system_clock> start,
            std::chrono::time_point<std::chrono::system_clock> end
        ) const;
        bool playerHasLoose(Point const& player, Point const& ghost);
        bool collide(Point const& a, Point const& b) const;
        void manageInputs(std::vector<arcade::Inputs> const& inputs);

    private:
        std::vector<arcade::Element> _elements;
        std::vector<arcade::Element> _constElements;
        std::unique_ptr<Player> _player;
        std::unique_ptr<Ghost> _enemy;
        PacgumManager _gumsManager;
};

#endif /* !PacmanGame_HPP_ */
