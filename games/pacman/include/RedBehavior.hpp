/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** RedBehavior
*/

#ifndef REDBEHAVIOR_HPP_
#define REDBEHAVIOR_HPP_

#include "Entity.hpp"
#include "IBehavior.hpp"

class RedBehavior : public IBehavior {
    public:
        RedBehavior(std::vector<arcade::Element> const& map, Entity const& player);
        ~RedBehavior();

        Point chase(Point const& pos, Point const& direction) const;
        Point goRandom(Point const& pos, Point const& direction) const;

    private:
        bool canMoveAt(Point const&pos, Point const& direction) const;
        int getDistance(Point const& a, Point const& b) const;
        bool comparePoints(Point const& a, Point const& b) const;
        Point invertPoint(Point const& a) const;

    private:
        std::vector<arcade::Element> const& _map;
        Entity const& _player;
};

#endif /* !REDBEHAVIOR_HPP_ */
