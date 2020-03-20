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

SFMLDisplay::SFMLDisplay() : _window(sf::VideoMode(800, 600), "Game")
{}

SFMLDisplay::~SFMLDisplay()
{
    if (_window.isOpen())
        _window.close();
}

void SFMLDisplay::display(std::vector<arcade::Element *> &elements)
{
    if (_window.isOpen() == false)
        return;
    _window.clear();
    for (auto it = elements.begin(); it != elements.end(); it++) {
        sf::Texture texture;
        if (!texture.loadFromFile((*it)->getFilename()))
            throw(std::string("Error: failed to load texture"));
        sf::Sprite sprite(texture);
        _window.draw(sprite);
    }
    _window.display();
}

std::vector<arcade::inputs> SFMLDisplay::getInputs(void)
{
    sf::Event event;
    std::vector<arcade::inputs> inputs;

    if (_window.isOpen() == false)
        return (inputs);
    while (_window.pollEvent(event)) {
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::Up)
                inputs.push_back(arcade::UP);
            if (event.key.code == sf::Keyboard::Q)
                inputs.push_back(arcade::QUIT);
        }
        if (event.type == sf::Event::Closed)
            inputs.push_back(arcade::QUIT);
    }
    return (inputs);
}
