/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** PacgumManager
*/

#ifndef PACGUMMANAGER_HPP_
#define PACGUMMANAGER_HPP_

#include <vector>
#include "Element.hpp"

static const std::string spritesFile("./games/pacman/assets/sprites.png");

class PacgumManager {
    public:
        PacgumManager();
        ~PacgumManager();

        std::vector<arcade::Element> const& getGums(void) const;

        void addGum(Point const& position);
        int removeTouchedGums(Point const& position);
        bool areGumsEmpty(void) const;

    private:
        bool collide(Point const& a, Point const& b) const;

    private:
        std::vector<arcade::Element> _gums;
};

#endif /* !PACGUMMANAGER_HPP_ */
