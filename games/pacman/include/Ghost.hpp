/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Ghost
*/

#ifndef GHOST_HPP_
#define GHOST_HPP_

#include <memory>
#include "IBehavior.hpp"
#include "Entity.hpp"

class Ghost : public Entity
{
    public:
        Ghost(
            Point direction,
            arcade::Element element,
            std::vector<arcade::Element> &map,
            Entity &player
        );
        ~Ghost();

        void move(void);

    private:
        std::unique_ptr<IBehavior> _behavior;
};

#endif /* !GHOST_HPP_ */
