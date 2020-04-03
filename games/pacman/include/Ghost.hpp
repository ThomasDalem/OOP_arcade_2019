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

enum mode_e {
    CHASE,
    RANDOM
};

class Ghost : public Entity
{
    public:
        Ghost(
            Point direction,
            Point position,
            arcade::Element element,
            std::vector<arcade::Element> &map,
            Entity &player
        );
        ~Ghost();

        void setDirection(Point const& dir);
        void move();

    private:
        std::unique_ptr<IBehavior> _behavior;
        std::chrono::time_point<std::chrono::system_clock> _prevBehaviorChange;
        mode_e _mode;
};

#endif /* !GHOST_HPP_ */
