/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#ifndef PacmanGame_HPP_
#define PacmanGame_HPP_

#include "IGameModule.hpp"
#include "Entity.hpp"

class PacmanGame : public arcade::IGameModule {
    public:
        PacmanGame();
        ~PacmanGame();

        void initGame(void);
        void playLoop(std::vector<arcade::Inputs> inputs);
        void restart(void);
        const std::vector<arcade::Element> &getElements() const;

    private:
        std::vector<arcade::Element> _elements;
        std::vector<arcade::Element> _constElements;
        Entity _player;
};

#endif /* !PacmanGame_HPP_ */
