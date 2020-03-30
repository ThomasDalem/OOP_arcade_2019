/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** Player
*/

#include "Player.hpp"

Player::Player(std::vector<arcade::Element> &map) :
    Entity(
        Point{0, 0}, Point{1, 1}, 
        arcade::Element{std::string(sprites), arcade::YELLOW, Point{1, 1}, arcade::Rect{Point{32, 33}, Point{289, 0}}},
        map
    ), _isAlive(true)
{}

Player::~Player()
{}

bool Player::isAlive(void) const
{
   return (_isAlive);
}