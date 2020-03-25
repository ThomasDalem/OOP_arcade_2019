/*
** EPITECH PROJECT, 2020
** OOP_arcade_2019
** File description:
** SFMLDisplay
*/

#include <iostream>
#include <memory>
#include "SFMLDisplay.hpp"

extern "C" SFMLDisplay *createObject()
{
    return (new SFMLDisplay);
}

SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(1200, 1000), "Game")
{}

SFMLDisplay::~SFMLDisplay()
{
    if (_window.isOpen())
        _window.close();
}

void SFMLDisplay::display(std::vector<arcade::Element> &elements)
{
    sf::Texture texture;
    sf::Sprite sprite;
    sf::Vector2f position;

    if (_window.isOpen() == false)
        return;
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        texture.loadFromFile(it->filename);
        sprite.setTexture(texture);
        position = sf::Vector2f(it->position.x * 100, it->position.y * 100);
        sprite.setPosition(position);
        _window.draw(sprite);
    }
    _window.display();
}

std::vector<arcade::Inputs> SFMLDisplay::getInputs(void)
{
    sf::Event event;
    std::vector<arcade::Inputs> inputs;

    if (_window.isOpen() == false)
        return (inputs);
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                inputs.push_back(arcade::UP);
            if (event.key.code == sf::Keyboard::Down)
                inputs.push_back(arcade::DOWN);
            if (event.key.code == sf::Keyboard::Left)
                inputs.push_back(arcade::LEFT);
            if (event.key.code == sf::Keyboard::Right)
                inputs.push_back(arcade::RIGHT);
            if (event.key.code == sf::Keyboard::Q)
                inputs.push_back(arcade::QUIT);
        }
        if (event.type == sf::Event::Closed)
            inputs.push_back(arcade::QUIT);
    }
    return (inputs);
}
