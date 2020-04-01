/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#ifndef PLAYER_HPP_
#define PLAYER_HPP_

#include "Entity.hpp"

class Player : public Entity {
    public:
        Player(std::vector<arcade::Element> &map);
        ~Player();

        bool isAlive(void) const;
        bool playLoose(void);

    private:
        bool _isAlive;
};

#endif /* !PLAYER_HPP_ */
