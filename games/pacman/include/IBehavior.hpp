/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** IBehavior
*/

#ifndef IBEHAVIOR_HPP_
#define IBEHAVIOR_HPP_

#include <vector>
#include "Element.hpp"
#include "Point.hpp"

const Point LEFT = {-1, 0};
const Point RIGHT = {1, 0};
const Point UP = {0, -1};
const Point DOWN = {0, 1};

const Point dirArray[4] = {
    {1, 0},
    {-1, 0},
    {0, -1},
    {0, 1}
};

class IBehavior {
    public:
        virtual ~IBehavior() = default;

        virtual Point chase(Point const& pos, Point const& direction) const = 0;
        virtual Point goRandom(Point const& pos, Point const& direction) const = 0;
};

#endif /* !IBEHAVIOR_HPP_ */
