/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#include <iostream>
#include "Player.hpp"

Player::Player(std::vector<arcade::Element> &map) :
    Entity(
        Point{0, 0}, Point{1, 1},
        arcade::Element{sprites, arcade::YELLOW, Point{1, 1}, arcade::Rect{Point{32, 33}, Point{289, 0}}},
        map
    ), _isAlive(true)
{}

Player::~Player()
{}

bool Player::isAlive() const
{
   return (_isAlive);
}

bool Player::playLoose()
{
    static std::chrono::time_point<std::chrono::system_clock> now = std::chrono::system_clock::now();
    static std::chrono::time_point<std::chrono::system_clock> prev;
    std::chrono::duration<double> elapsedTime;

    elapsedTime = now - prev;
    now = std::chrono::system_clock::now();
    if (elapsedTime.count() >= 0.06) {
        _element.rect.pos.x != 257 ? _element.rect.pos.x = 257 : 0;
        prev = now;
        if (_element.rect.pos.y <= 356) {
            _element.rect.pos.y += 33;
            return (false);
        }
    }
    return (true);
}
