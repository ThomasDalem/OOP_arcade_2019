/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacmanGame
*/

#ifndef PacmanGame_HPP_
#define PacmanGame_HPP_

#include "IGameModule.hpp"

class PacmanGame : public arcade::IGameModule {
    public:
        PacmanGame();
        ~PacmanGame();

        void initGame(void);
        void playLoop(void);
        void restart(void);
        const std::vector<arcade::Element> &getElements() const;
        const std::vector<arcade::Element *> &getConstElements() const;

    private:
        std::vector<arcade::Element> _elements;
};

#endif /* !PacmanGame_HPP_ */
